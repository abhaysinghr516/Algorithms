#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack, const vector<vector<int>> &adj) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }

    Stack.push(v);
}

void topologicalSort(int V, const vector<vector<int>> &adj) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }

    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "Topological Sort of the given graph: ";
    topologicalSort(V, adj);

    return 0;
}
