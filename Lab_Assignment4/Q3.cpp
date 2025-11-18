// QUESTION 3: INTERLEAVE FIRST HALF AND SECOND HALF OF QUEUE

#include<iostream>
using namespace std;

#define SIZE 50

class Queue {
public:
    int arr[SIZE], f, r;

    Queue() { f = r = -1; }

    bool empty() { return f == -1; }
    bool full() { return r == SIZE-1; }

    void push(int x) {
        if(full()) return;
        if(empty()) f = 0;
        arr[++r] = x;
    }
    int pop() {
        int x = arr[f];
        if(f == r) f = r = -1;
        else f++;
        return x;
    }
};

int main() {
    Queue q;
    int n, x;

    cin>>n;
    for(int i=0;i<n;i++) { cin>>x; q.push(x); }

    int half = n/2;
    Queue first;

    for(int i=0;i<half;i++) first.push(q.pop());

    while(!first.empty()) {
        cout<<first.pop()<<" ";
        cout<<q.pop()<<" ";
    }
}
