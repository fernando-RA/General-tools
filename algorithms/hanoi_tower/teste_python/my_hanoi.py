NUM_PEGS = 3
NUM_DISCS = 4
import sys
from string import ascii_uppercase
pegs = ascii_uppercase[:NUM_PEGS]

def main():

    # Build graph
    G = build()

    # Sample
    initial_state = readInitialState("input.txt")
    #checkDisksOrder(initial_state)
    final_state = readFinalState()
    print initial_state
    print final_state
    # Solution
    path = bfs(G, get_state_id(initial_state), get_state_id(final_state))[::-1]
    for i in range(len(path)-1):
        print(move(get_state(path[i]), get_state(path[i+1])))

def readInitialState(filename):
    state_map = [None] * NUM_DISCS
    lines = open(filename, 'r')
    for line in lines:
        peg_pair = line.strip().split('-')
        if peg_pair[1] is not '':
            disks_in_peg = enumerate(peg_pair[1].split(':'))
            for disk, value in disks_in_peg :
                state_map[int(value)-1] = peg_pair[0]
    file.close
    return state_map

def readFinalState():
    final_state_map = [None] * NUM_DISCS
    for peg in range(NUM_PEGS):
        final_state_configuration = raw_input("Ordem final de " + str(pegs[peg]) + ':\n')
        print (final_state_configuration)

        peg_pair = final_state_configuration.strip().split('-')
        if peg_pair[1] is not '':
            disks_in_peg = enumerate(peg_pair[1].split(':'))
            for disk, value in disks_in_peg :
                final_state_map[int(value)-1] = peg_pair[0]
    return final_state_map

def checkDisksOrder(mapa):
    for peg in mapa:
        array_size = len(mapa[peg])
        if(array_size) > 1:
            for disk, valor in enumerate(mapa[peg]):
                if(disk < array_size - 1):
                    next_disk = mapa[peg][(disk + 1)]
                if(next_disk > valor):
                    print("O disco " + str(valor) + " esta em cima do disco " + str(next_disk) + "\n")
                    return False
    return True

def get_state(state_id):
    state = []
    for i in range(NUM_DISCS):
        state += [pegs[state_id % NUM_PEGS]]
        state_id /= NUM_PEGS
    return state

def get_state_id(state):
    state_id = 0
    for disc in range(NUM_DISCS):
        state_id += NUM_PEGS**disc * pegs.index(state[disc])
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
    for disc in range(NUM_DISCS):
        disc_peg = get_peg(state_id,disc)
        if not fits_on_top(state_id, disc, disc_peg):
            continue
        for peg in range(NUM_PEGS):
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
    for state_id in range(NUM_PEGS**NUM_DISCS):
        G += [ get_valid_moves(state_id) ]
    return G

def bfs(G, src, dst):
    visited = [False] * NUM_PEGS**NUM_DISCS
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
    for i in range(NUM_DISCS):
        if src[i] != dst[i]:
            return '%d-%c' % (i+1, dst[i])

if __name__ == "__main__":
   main()
