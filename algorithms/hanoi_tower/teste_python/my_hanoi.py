import sys

def readInitialState():
    print "entrou"
    state_map = {}
    lines = sys.stdin.readlines()
    for line in lines:
        peg_pair = line.strip.split('-')
        state_map[peg_pair[0]] = peg_pair[1].split(':')
    file.close
    print state_map
    return state_map

readInitialState()
