import sys

MAX_MOVES = 11

def valid_moves(state, K):
    pegs, tops = [-1] * K, []
    for r, peg in enumerate(state):
        if pegs[peg] < 0:
            pegs[peg] = r
            for top_r, top_peg in tops:
                yield (top_r, top_peg, peg)
            tops.append((r, peg))
    for dst_peg, peg_r in enumerate(pegs):
        if peg_r < 0:
            for top_r, top_peg in tops:
                yield (top_r, top_peg, dst_peg)

def move_apply(state, move):
    r, src, dst = move
    return state[:r] + (dst,) + state[r + 1:]

def solve_bfs(initial_state, final_state, K):
    known_states = set()
    next_states = [(initial_state, [])]
    depth = 0
    while next_states and depth < MAX_MOVES:
        states, next_states = next_states, []
        for state, moves in states:
            for move in valid_moves(state, K):
                new_state = move_apply(state, move)
                if new_state in known_states:
                    continue
                new_moves = moves + [move]
                if new_state == final_state:
                    return new_moves
                next_states.append((new_state, new_moves))
                known_states.add(new_state)
        depth += 1

lines = sys.stdin.readlines()
N, K = [int(i) for i in lines[0].strip().split()]
initial_state = tuple(int(i) - 1 for i in lines[1].strip().split())
final_state = tuple(int(i) - 1 for i in lines[2].strip().split())

solution = solve_bfs(initial_state, final_state, K)
if solution:
    print len(solution)
    for disk, src, dst in solution:
        print src + 1, dst + 1
