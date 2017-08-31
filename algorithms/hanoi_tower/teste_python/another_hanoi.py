import sys

MAX_MOVES = 10

def main():
    lines = sys.stdin.readlines()

    [discs, npegs] = map(int, lines[0].split())
    #read in the initial and final states
    istate = tuple(int(n) - 1 for n in lines[1].split())
    fstate = tuple(int(n) - 1 for n in lines[2].split())

    print istate
    print fstate

    #call recursive function to find possible moves and
    #generate new states to add to tree
    tree = findStates(istate, fstate, npegs)
    solution = findSolution(istate, fstate, tree)

    if solution:
        print solution[0]
        for a, b in solution[1:]:
            print "{} {}".format(a,b)
    else:
        print "No solution found for {} max moves".format(MAX_MOVES)

def findTopDisks(state, npegs):
    """
    list the pegs with disks and the top disk radius in a dict with key being peg number
    and value being disk radius
    This function is used to find valid disks and their peg positions to make a move from
    """
    topdict = dict()
    for peg in range(npegs):
            if peg in state:
                topdict[peg] = state.index(peg)
    return topdict

def findValidMoves(state, npegs):
    """
    Finds the valid moves given the current state and number of pegs.
    Yields tuples consisting of source and destination pegs
    """
    #find the top disk of every peg number
    top_disks = findTopDisks(state, npegs)
    for from_peg, disk_r in top_disks.items():
        for dest_peg in range(npegs):
            if not top_disks.has_key(dest_peg): #dest peg is empty
                    yield (from_peg, dest_peg)
            elif top_disks[dest_peg] > disk_r:
                    yield (from_peg, dest_peg)

def findStates(istate, fstate, npegs):
    """
    Generates new states first by calling findValidMoves on current state to get valid moves.
    Then generates the new states and put them in the tree implemented using a dict.
    Key of the dict is the current state, and value is the state that leads to that state.
    """
    queue = [(istate, 0)]
    tree = {istate: None}
    while queue and (queue[0][1] < MAX_MOVES):
        cstate = queue[0][0]
        cmove = queue[0][1]
        queue.pop(0)
        #enumerate and find all valid moves and add to queue
        for from_peg, dest_peg in findValidMoves(cstate, npegs):
            if from_peg in cstate:
                nstate = list(cstate)
                nstate[cstate.index(from_peg)] = dest_peg
                nstate = tuple(nstate)
                if nstate not in tree: #new state never been found!
                    tree[nstate] = cstate
                    if nstate == fstate:
                        return tree
                    queue.append((nstate, cmove+1))
    return tree


def findSolution(istate, fstate, tree):
    """
    back track through dict and find the moves taken to get from istate and final state
    """
    solution = []
    cstate = fstate
    if fstate in tree:
        while (cstate != istate):
            #compare current state and previous
            #find the difference, record in tuple and add to list of solution moves
            pstate = tree[cstate]
            for p, c in zip(pstate, cstate):
                if p != c:
                    solution.insert(0, (p+1, c+1)) #add one to adjust for 0 offset
                    break
            cstate = pstate
        solution.insert(0, len(solution))

    return solution

if __name__ == "__main__":
   main()
