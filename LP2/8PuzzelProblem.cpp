#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<int> state;
    int g, h;
    string key;
};

struct Compare {
    bool operator()(Node &a, Node &b) {
        return (a.g + a.h) > (b.g + b.h);
    }
};

int manhattan(const vector<int> &s, const vector<int> &goal) {
    int dist = 0;
    for (int i = 0; i < 9; i++) {
        if (s[i] != 0) {
            int val = s[i];
            int gi = find(goal.begin(), goal.end(), val) - goal.begin();
            dist += abs((i/3) - (gi/3)) + abs((i%3) - (gi%3));
        }
    }
    return dist;
}

int main(){
    cout << "Enter Initial State (3x3, row by row):\n";
    vector<int> start(9), goal(9);
    for(int i = 0; i < 9; i++) cin >> start[i];

    cout << "Enter Final State (3x3, row by row):\n";
    for(int i = 0; i < 9; i++) cin >> goal[i];

    string startKey = "";
    for (int v : start) startKey += char('0' + v);

    priority_queue<Node, vector<Node>, Compare> pq;
    unordered_map<string, bool> visited;

    Node root;
    root.state = start;
    root.g = 0;
    root.h = manhattan(start, goal);
    root.key = startKey;

    pq.push(root);

    int moves[4] = {-3,3,-1,1};

    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();

        if (visited[cur.key]) continue;
        visited[cur.key] = true;

        if (cur.state == goal){
            cout << "Goal reached with cost = " << cur.g << endl;
            return 0;
        }

        int z = find(cur.state.begin(), cur.state.end(), 0) - cur.state.begin();

        for (int m = 0; m < 4; m++){
            int nz = z + moves[m];

            if (nz < 0 || nz >= 9) continue;
            if ((z%3 == 2 && moves[m] == 1) || (z%3 == 0 && moves[m] == -1)) continue;

            vector<int> nextState = cur.state;
            swap(nextState[z], nextState[nz]);
            
            string nextKey = "";
            for (int v : nextState) nextKey += char('0' + v);

            if (!visited[nextKey]) {
                Node child;
                child.state = nextState;
                child.g = cur.g + 1;
                child.h = manhattan(nextState, goal);
                child.key = nextKey;
                pq.push(child);
            }
        }
    }

    cout << "No Solution!" << endl;
    return 0;
}
