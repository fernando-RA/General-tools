#include<bits/stdc++.h>
using namespace std;

const int INF = 100000000;

int n,m,k;
int distanceMatrix[1000+10][1024+10]; 
int typeOfFishAtIthShop[1000+10]; // a array to store the types of fish at ith shop

set <pair<int, pair<int, int>>> setOfNextNodeToBeVisited; // Set S to store whick next node to be visited
vector<pair<int,int>> adjMatrixToStoreEdges[1000 + 10]; // adj matrix to store the edges


inline void push (int vn, int vm, int vv) {
    if(distanceMatrix[vn][vm] <= vv) return; // do nothing if there exists some distance to vn node with vm fish collected less than vv. 
    pair<int, pair<int, int>> mp = make_pair(distanceMatrix[vn][vm], make_pair(vn,vm)); // create mp, an element which will be insterted to set S
    if(setOfNextNodeToBeVisited.find(mp) != setOfNextNodeToBeVisited.end()) {
        setOfNextNodeToBeVisited.erase(setOfNextNodeToBeVisited.find(mp)); // if node is already in the set S then remove it
    }
    // else, insert it
    distanceMatrix[vn][vm] = vv;
    mp.first = vv;
    setOfNextNodeToBeVisited.insert(mp);
};

int main() {
    cin >> n >> m >> k; // input N,M,K from the problem's dataset

    // input a[i], each element will store number of fish can be found on ith shop
    for (int i = 1; i <= n; i++){
        int fish;
        cin >> fish;
        for(int j = 1; j <= fish; j++) {
            int x;
            cin >> x;
            typeOfFishAtIthShop[i] |= (1 << (x-1));
        }
    }

    // input adjacency matrix
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adjMatrixToStoreEdges[x].push_back(make_pair(y,z));
        adjMatrixToStoreEdges[y].push_back(make_pair(x,z));
    }

    // initialize distance matrix with infinity
    for (int i = 1; i <= n; i++ ){ 
        for(int j = 0; j < (1 << k); j++) {
            distanceMatrix[i][j] = INF;
        }
    }

    // push the very first node to the set S
    push(1, typeOfFishAtIthShop[1], 0);
    while(setOfNextNodeToBeVisited.size() > 0) {
        int vn = setOfNextNodeToBeVisited.begin()->second.first;
        int vm = setOfNextNodeToBeVisited.begin()->second.second;
        setOfNextNodeToBeVisited.erase(setOfNextNodeToBeVisited.begin()); // remove the current element from the set S

        // keep adding all the nodes that can be visited from current node
        for (int i = 0; i < adjMatrixToStoreEdges[vn].size(); i++) {
            push(adjMatrixToStoreEdges[vn][i].first, vm | typeOfFishAtIthShop[adjMatrixToStoreEdges[vn][i].first], distanceMatrix[vn][vm] + adjMatrixToStoreEdges[vn][i].second);
        }
    }

    // if the control comest to this part then all the nodes have been visited
    int ret = INF;
    for(int i = 0; i <(1 << k); i++){
        for(int j = i; j < (1<<k); j++){
            if((i | j) == ((1 << k) -1)) {
                ret = min(ret, max(distanceMatrix[n][i], distanceMatrix[n][j])); // find the maximum of two path, which is the minimum among others and store it
            }
        }
    }
    cout << ret << endl;
    return 0;
}