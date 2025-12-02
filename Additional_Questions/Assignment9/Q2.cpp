// Shortest Path in Grid (Dijkstra on Grid)
#include <iostream>
#define INF 99999
using namespace std;

int m, n;
int grid[50][50];
int dist[50][50];
bool visited[50][50];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool valid(int x,int y){ return x>=0 && x<m && y>=0 && y<n; }

int main(){
    cin >> m >> n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
            dist[i][j] = INF;
            visited[i][j] = false;
        }

    dist[0][0] = grid[0][0];

    for(int k=0;k<m*n;k++){
        int minDist = INF, ux=-1, uy=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && dist[i][j]<minDist){
                    minDist = dist[i][j];
                    ux = i; uy = j;
                }
            }
        }
        if(ux==-1) break;
        visited[ux][uy]=true;

        for(int d=0;d<4;d++){
            int vx=ux+dx[d], vy=uy+dy[d];
            if(valid(vx,vy) && !visited[vx][vy]){
                if(dist[ux][uy]+grid[vx][vy] < dist[vx][vy])
                    dist[vx][vy] = dist[ux][uy]+grid[vx][vy];
            }
        }
    }

    cout << dist[m-1][n-1] << endl;
    return 0;
}
