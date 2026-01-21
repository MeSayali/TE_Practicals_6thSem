#include <bits/stdc++.h>
using namespace std;

// store in 1d state 
struct Node {
    vector<int> state; // state = {1,2,3,4,0,5,6,7,8} puzzel to store as 1D Array
    int g, h;
    string key; //key = "123405678"
};

struct Compare { //define how nodes are ordered in priority_queue
    bool operator()(Node &a, Node &b) {
        return (a.g + a.h) > (b.g + b.h); // f(a)>f(b) then f(a) has lower priority
    }
};

int manhattan(const vector<int> &s, const vector<int> &goal) {
    int dist = 0;
    for (int i = 0; i < 9; i++) {
        if (s[i] != 0) { // except 0 calculate for all
            int val = s[i];
            int gi = find(goal.begin(), goal.end(), val) - goal.begin(); // finding goal index need to substract goal.begin since find returns iterator-> convert to index
            dist += abs((i/3) - (gi/3)) + abs((i%3) - (gi%3)); // ∣current_row−goal_row∣+∣current_col−goal_col∣
            // i/3 = row i%3 = column g/3=row g%3 = column
        }
    }
    return dist;
}

int main(){
    cout << "Enter Initial State (3x3, row by row):\n"; // Initail State
    vector<int> start(9), goal(9);
    for(int i = 0; i < 9; i++) cin >> start[i];

    cout << "Enter Final State (3x3, row by row):\n"; // Final State
    for(int i = 0; i < 9; i++) cin >> goal[i];

    string startKey = "";
    for (int v : start) startKey += char('0' + v); //convert number to char

    priority_queue<Node, vector<Node>, Compare> pq;//store all open states gives the state with mininum g+h
    unordered_map<string, bool> visited;//to avoid revisting same puzzel again and again

    Node root;
    root.state = start; //{1,2,3,4,5,0,6,7,8}
    root.g = 0;
    root.h = manhattan(start, goal);
    root.key = startKey; //"123450678"

    pq.push(root);

    int moves[4] = {-3,3,-1,1}; // move up, down, left, right

    while(!pq.empty()){
        Node cur = pq.top(); // minimum (g+h)
        pq.pop();

        if (visited[cur.key]) continue; //if already visited ignore
        visited[cur.key] = true; // else mark visited

        if (cur.state == goal){
            cout << "Goal reached with cost = " << cur.g << endl;
            return 0;
        }

        int z = find(cur.state.begin(), cur.state.end(), 0) - cur.state.begin(); // find position of 0/blank tile

        for (int m = 0; m < 4; m++){
            int nz = z + moves[m]; //new blank position current z position with moves[-3],moves[3],moves[-1],moves[1]

            if (nz < 0 || nz >= 9) continue; // out of bound
            if ((z%3 == 2 && moves[m] == 1) || (z%3 == 0 && moves[m] == -1)) continue;// representing 2d array as 1d so from 1st row 3 column 0 may come down if these values

            vector<int> nextState = cur.state;
            swap(nextState[z], nextState[nz]); // z%3=1 this swap changes position from original state
            
            string nextKey = ""; // check visited or not
            for (int v : nextState) nextKey += char('0' + v); //interger to char

            if (!visited[nextKey]) {
                Node child;
                child.state = nextState;
                child.g = cur.g + 1;
                child.h = manhattan(nextState, goal);
                child.key = nextKey;
                pq.push(child); // indirectly calculate f(n) = g(n)
            }
        }
    }

    cout << "No Solution!" << endl;
    return 0;
}
