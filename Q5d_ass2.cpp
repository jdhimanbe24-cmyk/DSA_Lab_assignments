#include <iostream>
using namespace std;

struct UpperTri {
    int n;
    int *A;
    UpperTri(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) A[i]=0;
    }
    int index(int i,int j){ return j*(j+1)/2+i; } // valid only if j>=i
    void set(int i,int j,int val){ if(j>=i) A[index(i,j)]=val; }
    int get(int i,int j){ return (j>=i)? A[index(i,j)] : 0; }
    void display(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<get(i,j)<<" ";
            cout<<"\n";
        }
    }
};

int main(){
    UpperTri u(4);
    u.set(0,0,5); u.set(0,1,1); u.set(0,2,2); u.set(1,1,9); u.set(2,2,7); u.set(3,3,4);
    u.display();
    return 0;
}