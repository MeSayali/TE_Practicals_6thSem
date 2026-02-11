#include <bits/stdc++.h>
using namespace std;

void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {//v no. of vertex src sorce vertex

    // Min-heap priority queue (distance, vertex) to get the vertex with min dist
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V, INT_MAX);// Distance vector to store shortest distance from source

    dist[src] = 0; //dist of source is 0
    pq.push({0, src}); // put it in priporty queue

    while (!pq.empty()) { //main logic to find min dist
        //get vertex with min dist
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;//if dist is not correct ignore it

        for (auto edge : adj[u]) { //vertex u ke neighbours check 
            int v = edge.first;//vertex
            int w = edge.second;//weight

            if (dist[u] + w < dist[v]) {//check new path is short 
                dist[v] = dist[u] + w;//if yes update 
                pq.push({dist[v], v});//put it in queue
            }
        }
    }

    cout << "\nShortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line for directed graph
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(V, adj, source);

    return 0;
}

