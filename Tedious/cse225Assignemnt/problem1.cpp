#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printResult(bool result){
    if (result) 
        cout<<"True\n" ;

    else 
        cout<<"False\n";
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if (n <= 0) return false;
    if (source < 0 || source >= n || destination < 0 || destination >= n) return false;
    if (source == destination) return true; 

    // Build the adjacency list
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        if (edge.size() != 2) continue; 
        int u = edge[0];
        int v = edge[1];
        if (u < 0 || u >= n || v < 0 || v >= n) continue; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == destination) {
            return true;
        }
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false;
}

int main() {
    int n = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}};
    vector<vector<int>> edges2 = {{0, 1} , {0, 2} , {3, 5} , {5,4} , {4,3}};
    int source = 0;
    int destination = 2;

    bool result1 = validPath(n, edges1, source, destination);
    bool result2 = validPath(n, edges2, source, destination);
    
    printResult(result1);
    printResult(result2);
    return 0;
}
