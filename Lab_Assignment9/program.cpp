// BFS, DFS, Kruskal’s MST, Prim’s MST, and Dijkstra’s algorithmm
#include <iostream>
#define MAX 100
#define INF 9999
using namespace std;

class Graph {
public:
    int V;
    int adj[MAX][MAX]; 
    Graph(int vertices) {
        V = vertices;
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v, int w=1, bool undirected=true) {
        adj[u][v] = w;
        if(undirected) adj[v][u] = w;
    }

    
    void BFS(int start) {
        int queue[MAX], front=0, rear=0;
        bool visited[MAX];
        for(int i=0;i<V;i++) visited[i] = false;

        queue[rear++] = start;
        visited[start] = true;

        cout << "BFS: ";
        while(front != rear) {
            int u = queue[front++];
            cout << u << " ";
            for(int v=0; v<V; v++) {
                if(adj[u][v]!=0 && !visited[v]) {
                    queue[rear++] = v;
                    visited[v] = true;
                }
            }
        }
        cout << endl;
    }

    
    void DFSUtil(int u, bool visited[]) {
        visited[u] = true;
        cout << u << " ";
        for(int v=0; v<V; v++) {
            if(adj[u][v]!=0 && !visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int start) {
        bool visited[MAX];
        for(int i=0;i<V;i++) visited[i] = false;
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }

   
    int findParent(int parent[], int i) {
        if(parent[i]==i) return i;
        return findParent(parent, parent[i]);
    }

    void unionSet(int parent[], int a, int b) {
        int pa = findParent(parent, a);
        int pb = findParent(parent, b);
        parent[pa] = pb;
    }

    void KruskalMST() {
        int edges[MAX*MAX][3]; 
        int ecount=0;
        for(int i=0;i<V;i++)
            for(int j=i;j<V;j++)
                if(adj[i][j]!=0) {
                    edges[ecount][0]=i;
                    edges[ecount][1]=j;
                    edges[ecount][2]=adj[i][j];
                    ecount++;
                }

    
        for(int i=0;i<ecount-1;i++)
            for(int j=0;j<ecount-i-1;j++)
                if(edges[j][2] > edges[j+1][2]) {
                    int temp0=edges[j][0], temp1=edges[j][1], temp2=edges[j][2];
                    edges[j][0]=edges[j+1][0]; edges[j][1]=edges[j+1][1]; edges[j][2]=edges[j+1][2];
                    edges[j+1][0]=temp0; edges[j+1][1]=temp1; edges[j+1][2]=temp2;
                }

        int parent[MAX];
        for(int i=0;i<V;i++) parent[i]=i;

        cout << "Kruskal's MST: ";
        int count=0;
        for(int i=0;i<ecount && count<V-1;i++) {
            int u=edges[i][0], v=edges[i][1], w=edges[i][2];
            int pu=findParent(parent,u), pv=findParent(parent,v);
            if(pu != pv) {
                cout << "("<<u<<","<<v<<") ";
                unionSet(parent, pu, pv);
                count++;
            }
        }
        cout << endl;
    }

   
    void PrimMST() {
        int selected[MAX];
        for(int i=0;i<V;i++) selected[i]=0;
        selected[0]=1;

        cout << "Prim's MST: ";
        int edgesCount=0;
        while(edgesCount<V-1) {
            int min=INF, u=-1, v=-1;
            for(int i=0;i<V;i++) {
                if(selected[i]) {
                    for(int j=0;j<V;j++) {
                        if(!selected[j] && adj[i][j]!=0 && adj[i][j]<min) {
                            min=adj[i][j];
                            u=i; v=j;
                        }
                    }
                }
            }
            if(u!=-1 && v!=-1) {
                cout << "("<<u<<","<<v<<") ";
                selected[v]=1;
                edgesCount++;
            }
        }
        cout << endl;
    }

   
    void Dijkstra(int start) {
        int dist[MAX], visited[MAX];
        for(int i=0;i<V;i++) {
            dist[i]=INF;
            visited[i]=0;
        }
        dist[start]=0;

        for(int count=0;count<V-1;count++) {
            int u=-1, minDist=INF;
            for(int i=0;i<V;i++)
                if(!visited[i] && dist[i]<minDist) {
                    minDist=dist[i];
                    u=i;
                }
            if(u==-1) break;
            visited[u]=1;
            for(int v=0;v<V;v++)
                if(adj[u][v]!=0 && !visited[v] && dist[u]+adj[u][v]<dist[v])
                    dist[v]=dist[u]+adj[u][v];
        }

        cout << "Dijkstra distances from " << start << ": ";
        for(int i=0;i<V;i++) {
            if(dist[i]==INF) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,8);
    g.addEdge(1,4,5);
    g.addEdge(2,4,7);
    g.addEdge(3,4,9);

    g.BFS(0);
    g.DFS(0);
    g.KruskalMST();
    g.PrimMST();
    g.Dijkstra(0);

    return 0;
}
