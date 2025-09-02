#include <iostream>
using namespace std;

struct Symmetric {
    int n;
    int *A;
    Symmetric(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) A[i]=0;
    }
    int index(int i,int j){ if(i>=j) return i*(i+1)/2+j; else return j*(j+1)/2+i; }
    void set(int i,int j,int val){ A[index(i,j)]=val; }
    int get(int i,int j){ return A[index(i,j)]; }
    void display(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<get(i,j)<<" ";
            cout<<"\n";
        }
    }
};

int main(){
    Symmetric s(3);
    s.set(0,0,4); s.set(1,0,2); s.set(1,1,5); s.set(2,0,7); s.set(2,2,9);
    s.display();
    return 0;
}