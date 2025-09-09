// to find multiplication of two sparse matrix assuming matrix is represented using triplets.
#include<iostream>
using namespace std;
void show(int trip[][3],int t){
    for(int i=0;i<t;i++)cout<<trip[i][0]<<" "<<trip[i][1]<<" "<<trip[i][2]<<"\n";
}
int multiply(int a[][3],int t1,int b[][3],int t2,int res[][3],int r1,int c1,int r2,int c2){
    int k=0;
    if(c1!=r2)return 0;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            int sum=0;
            for(int x=0;x<t1;x++)if(a[x][0]==i)
                for(int y=0;y<t2;y++)if(b[y][1]==j&&b[y][0]==a[x][1])sum+=a[x][2]*b[y][2];
            if(sum){res[k][0]=i;res[k][1]=j;res[k][2]=sum;k++;}
        }
    }
    return k;
}
int main(){
    int a[2][3]={{0,0,1},{1,2,2}},b[2][3]={{0,1,3},{2,0,4}},res[10][3];
    int t=multiply(a,2,b,2,res,2,3,3,2);
    show(res,t);
}
