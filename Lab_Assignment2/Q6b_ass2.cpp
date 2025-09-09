// to find addition of two sparse matrix assuming matrix is represented using triplets.
#include <iostream>
using namespace std;
void show(int trip[][3],int t){
    for(int i=0;i<t;i++)cout<<trip[i][0]<<" "<<trip[i][1]<<" "<<trip[i][2]<<"\n";
}
int add(int a[][3],int t1,int b[][3],int t2,int res[][3]){
    int i=0,j=0,k=0;
    while(i<t1&&j<t2){
        if(a[i][0]<b[j][0]||(a[i][0]==b[j][0]&&a[i][1]<b[j][1])){res[k][0]=a[i][0];res[k][1]=a[i][1];res[k][2]=a[i][2];i++;k++;}
        else if(b[j][0]<a[i][0]||(b[j][0]==a[i][0]&&b[j][1]<a[i][1])){res[k][0]=b[j][0];res[k][1]=b[j][1];res[k][2]=b[j][2];j++;k++;}
        else{res[k][0]=a[i][0];res[k][1]=a[i][1];res[k][2]=a[i][2]+b[j][2];i++;j++;k++;}
    }
    while(i<t1){res[k][0]=a[i][0];res[k][1]=a[i][1];res[k][2]=a[i][2];i++;k++;}
    while(j<t2){res[k][0]=b[j][0];res[k][1]=b[j][1];res[k][2]=b[j][2];j++;k++;}
    return k;
}
int main(){
    int a[2][3]={{0,0,2},{1,1,3}},b[2][3]={{0,0,5},{1,1,6}},res[10][3];
    int t=add(a,2,b,2,res);
    show(res,t);
}
