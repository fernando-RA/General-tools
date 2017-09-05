num_pegs = 5
num_discs = 8


def get_state(state_id):
    state = []
    for i in range(num_discs):
        state += [pegs[state_id % num_pegs]]
        state_id /= num_pegs
    return state

def get_state_id(state):
    state_id = 0
    for disc in range(num_discs):
        state_id += num_pegs**disc * pegs.index(state[disc])
    return state_id

def get_peg(state_id, disc):
    state = get_state(state_id)
    return pegs.index(state[disc])

def fits_on_top(state_id, disc, peg):
    state = get_state(state_id)
    for i in range(disc):
        if state[i] == pegs[peg]:
            return False
    return True

def get_valid_moves(state_id):
    valid_moves = []
    for disc in range(num_discs):
        disc_peg = get_peg(state_id,disc)
        if not fits_on_top(state_id, disc, disc_peg):
            continue
        for peg in range(num_pegs):
            if peg == disc_peg:
                continue
            if not fits_on_top(state_id, disc, peg):
                continue
            state = get_state(state_id)
            state[disc] = pegs[peg]
            valid_moves += [get_state_id(state)]
    return valid_moves

def build():
    G = []
    for state_id in range(num_pegs**num_discs):
        G += [ get_valid_moves(state_id) ]
    return G

def bfs(G, src, dst):
    visited = [False] * num_pegs**num_discs
    queue = [ (0,src) ]
    last_of_layer = src

    i = 0
    while i < len(queue):
        pos,state_id = queue[i]
        if state_id == dst:
            break
        visited[state_id] = True
        for next_state in G[state_id]:
            if not visited[next_state]:
                queue += [ (i,next_state) ]
        if state_id == last_of_layer:
            pos,last_of_layer = queue[-1]
        i += 1

    path = []
    while i:
        i,state_id = queue[i]
        path += [state_id]
    path += [src]

    return path

def move(src, dst):
    for i in range(num_discs):
        if src[i] != dst[i]:
            return 'disc %d from %c to %c' % (i+1, src[i], dst[i])

if __name__ == "__main__":
    # Build graph
    G = build()

    # Sample
    src = ['A', 'A', 'A', 'A', 'A', 'A', 'A', 'A']
    dst = ['B', 'B', 'B', 'B', 'B', 'B', 'B', 'B']

    # Solution
    path = bfs(G, get_state_id(src), get_state_id(dst))[::-1]
    for i in range(len(path)-1):
        print(move(get_state(path[i]), get_state(path[i+1])))
