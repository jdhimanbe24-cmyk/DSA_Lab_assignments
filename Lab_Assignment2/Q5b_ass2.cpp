// to store a tri-diagonal matrix in a efficient way
#include <iostream>
using namespace std;

struct TriDiagonal {
    int n;
    int *A;
    TriDiagonal(int n) {
        this->n=n;
        A=new int[3*n-2];
        for(int i=0;i<3*n-2;i++) A[i]=0;
    }
    void set(int i,int j,int val){
        if(i==j) A[i]=val;
        else if(i==j+1) A[n+(i-1)]=val;     // lower diag
        else if(i+1==j) A[2*n-1+i]=val;     // upper diag
    }
    int get(int i,int j){
        if(i==j) return A[i];
        else if(i==j+1) return A[n+(i-1)];
        else if(i+1==j) return A[2*n-1+i];
        return 0;
    }
    void display(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<get(i,j)<<" ";
            cout<<"\n";
        }
    }
};

int main(){
    TriDiagonal t(4);
    t.set(0,0,5); t.set(0,1,1); t.set(1,0,2); t.set(1,1,8);
    t.set(1,2,3); t.set(2,1,4); t.set(2,2,6); t.set(2,3,9);
    t.set(3,2,7); t.set(3,3,10);
    t.display();
    return 0;

}
