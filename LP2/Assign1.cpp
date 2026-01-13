#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Recursive DFS
void DFS(int v, vector<int> adj[], bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if (!visited[u])
        {
            DFS(u, adj, visited);
        }
    }
}

// BFS using Queue
void BFS(int start, vector<int> adj[], int V)
{
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i];
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    bool visited[V] = {false};

    cout << "\nDFS Traversal: ";
    DFS(start, adj, visited);

    cout << "\nBFS Traversal: ";
    BFS(start, adj, V);

    return 0;
}
