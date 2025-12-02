// Graph Traversal Count
#include <iostream>
using namespace std;

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int V, E;

void dfs(int u) {
    visited[u] = true;
    for(int v = 0; v < V; v++) {
        if(adj[u][v] && !visited[v]) dfs(v);
    }
}

int main() {
    cin >> V >> E;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) adj[i][j] = 0;
        visited[i] = false;
    }
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    int count = 0;
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
