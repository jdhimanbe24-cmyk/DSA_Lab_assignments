#include <iostream>
using namespace std;

struct LowerTri {
    int n;
    int *A;
    LowerTri(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) A[i]=0;
    }
    int index(int i,int j){ return i*(i+1)/2+j; } // valid only if i>=j
    void set(int i,int j,int val){ if(i>=j) A[index(i,j)] = val; }
    int get(int i,int j){ return (i>=j)? A[index(i,j)] : 0; }
    void display(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<get(i,j)<<" ";
            cout<<"\n";
        }
    }
};

int main(){
    LowerTri l(4);
    l.set(0,0,5); l.set(1,0,2); l.set(1,1,8); l.set(2,0,3); l.set(2,2,6);
    l.set(3,0,7); l.set(3,3,9);
    l.display();
    return 0;
}