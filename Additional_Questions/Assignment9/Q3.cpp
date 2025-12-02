// Network Delay Time (Dijkstra on Directed Graph)
#include <iostream>
#define INF 99999
using namespace std;

int N, M, K;
int adj[100][100];

int main(){
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) adj[i][j]=INF;

    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--; // assuming input is 1-indexed
        adj[u][v] = w;
    }

    bool visited[100];
    int dist[100];
    for(int i=0;i<N;i++){
        dist[i]=INF; visited[i]=false;
    }

    dist[K-1]=0;

    for(int count=0; count<N; count++){
        int u=-1,minDist=INF;
        for(int i=0;i<N;i++)
            if(!visited[i] && dist[i]<minDist){
                minDist = dist[i];
                u=i;
            }
        if(u==-1) break;
        visited[u]=true;
        for(int v=0;v<N;v++){
            if(adj[u][v]!=INF && !visited[v]){
                if(dist[u]+adj[u][v]<dist[v]) dist[v]=dist[u]+adj[u][v];
            }
        }
    }

    int ans=0;
    for(int i=0;i<N;i++){
        if(dist[i]==INF){ cout << -1 << endl; return 0;}
        if(dist[i]>ans) ans=dist[i];
    }
    cout << ans << endl;
    return 0;
}
