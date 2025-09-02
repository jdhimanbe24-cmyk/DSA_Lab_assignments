#include <iostream>
using namespace std;

struct Diagonal {
    int n;
    int *A;
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
        for(int i=0;i<n;i++) A[i]=0;
    }
    void set(int i,int j,int val) { if(i==j) A[i]=val; }
    int get(int i,int j) { return (i==j)? A[i]:0; }
    void display() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout<<get(i,j)<<" ";
            cout<<"\n";
        }
    }
};

int main(){
    Diagonal d(4);
    d.set(0,0,5); d.set(1,1,8); d.set(2,2,3); d.set(3,3,7);
    d.display();
    return 0;
}
