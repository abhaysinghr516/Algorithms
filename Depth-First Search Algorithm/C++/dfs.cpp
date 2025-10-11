#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& visited) {
    visited[node] = 1;
    cout << node << " "; // process the node

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 6; // number of nodes
    vector<int> adj[n + 1];

    // Example: undirected graph edges
    adj[1] = {2, 3};
    adj[2] = {1, 4, 5};
    adj[3] = {1, 6};
    adj[4] = {2};
    adj[5] = {2};
    adj[6] = {3};

    vector<int> visited(n + 1, 0);

    cout << "DFS Traversal: ";
    dfs(1, adj, visited); // start DFS from node 1
    cout << endl;

    return 0;
}
