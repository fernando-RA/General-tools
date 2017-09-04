import sys

PEG_NUMBER = 3
DISK_NUMBER = 4

def main():
    initial_state = readInitialState("input.txt")
    checkDisksOrder(initial_state)
    final_state = readFinalState()

    print initial_state
    print final_state

    print("O estado inicial e igual ao estado final? R:" + str(checkStatesEquality(initial_state, final_state)))
    #solve(initial_state, final_state)


def readInitialState(filename):
    state_map = {}
    lines = open(filename, 'r')
    for line in lines:
        peg_pair = line.strip().split('-')
        state_map[peg_pair[0]] = peg_pair[1].split(':')
    file.close
    return state_map

def readFinalState():
    org = ['A','B','C']
    final_state_map = {}

    for peg in range(3):
        final_state_configuration = raw_input("Ordem de " + str(org[peg]) + '\n')
        print final_state_configuration
        peg_pair = final_state_configuration.strip().split('-')
        final_state_map[peg_pair[0]] = peg_pair[1].split(':')

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

def checkStatesEquality(initial_state, final_state):
    for peg in initial_state:
        if(len(initial_state[peg]) == len(final_state[peg])):
            for disk in range(len(initial_state[peg])):
                if initial_state[peg][disk] != final_state[peg][disk]:
                    return False
        else:
            return False
    return True

if __name__ == "__main__":
   main()
