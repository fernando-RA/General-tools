import sys

def main():
    initial_state = readInitialState()
    checkOrder(initial_state)
    final_state = readFinalState()
    print("O estado inicial e igual ao estado final? R:" + str(check(initial_state, final_state)))
    #solve(initial_state, final_state)


def readInitialState():
    state_map = {}
    #lines = sys.stdin.readlines()
    lines = open('input.txt', 'r')
    for line in lines:
        peg_pair = line.strip().split('-')
        state_map[peg_pair[0]] = peg_pair[1].split(':')
    file.close
    return state_map


def checkOrder(mapa):
    for k in mapa:
        if(len(mapa[k])) > 1:
            maior = mapa[k][0]
            for valor in mapa[k]:
                if(maior < valor):
                    print("O disco " + str(valor) + " ta errado")
                    raise ValueError, 'Input invalido'

def readFinalState():
    org = ['A','B','C']
    final_state_map = {}
    pos = []

    for i in range(3):
        final_state_configuration = raw_input("Ordem de " + str(org[i]) + '\n')
        print final_state_configuration
        peg_pair = final_state_configuration.strip().split('-')
        final_state_map[peg_pair[0]] = peg_pair[1].split(':')

    return final_state_map


"""
def findState(initial_state, final_state, pegs=3):

    queue = [(initial_state, 0)]
    tree = {istate: None}

    while queue:
        cstate = queue[0][0]
        cmove = queue[0][1]
        queue.pop(0)

        for from_peg, dest_peg in findValidMoves(cstate):
            if from_peg in cstate:
                nstate = list(cstate)
                nstate[cstate.index(from_peg)] = dest_peg
                nstate = tuple(nstate)
                if nstate not in tree:
                    tree[nstate] = cstate
                    if nstate == fstate:
                        return tree
                    queue.append((nstate, cmove +1 ))

    return tree

def moveTower(height, fromPole, toPole, withPole):
    if height > 1:
        print("  "*(3-height), "movetower: ", height, fromPole, toPole)
        moveTower(height - 1, fromPole, withPole, toPole)
        moveDisk(fromPole, toPole)
        moveTower(height - 1, withPole, toPole, fromPole)

def moveDisk(fp, tp):
    print("Movimento de disco ", fp, "para", tp)

"""


def check(initial_state, final_state):
    for k in initial_state:
        if(len(initial_state[k]) == len(final_state[k])):
            for i in range(len(initial_state[k])):
                if initial_state[k][i] != final_state[k][i]:
                    return False
        else:
            return False
    return True

if __name__ == "__main__":
   main()
