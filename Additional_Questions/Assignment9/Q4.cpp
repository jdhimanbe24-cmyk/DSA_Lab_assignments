// Number of Islands (DFS)
#include <iostream>
using namespace std;

int M,N;
char grid[50][50];
bool visited[50][50];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

bool valid(int x,int y){ return x>=0 && x<M && y>=0 && y<N; }

void dfs(int x,int y){
    visited[x][y]=true;
    for(int d=0;d<4;d++){
        int nx=x+dx[d], ny=y+dy[d];
        if(valid(nx,ny) && !visited[nx][ny] && grid[nx][ny]=='1')
            dfs(nx,ny);
    }
}

int main(){
    cin >> M >> N;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++){
            cin >> grid[i][j];
            visited[i][j]=false;
        }

    int islands=0;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                dfs(i,j);
                islands++;
            }
        }

    cout << islands << endl;
    return 0;
}
