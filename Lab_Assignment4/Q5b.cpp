// QUESTION 5(b): STACK USING ONE QUEUE

#include<iostream>
using namespace std;

#define SIZE 50

class Queue {
public:
    int arr[SIZE], f, r;
    Queue(){ f=r=-1; }

    void push(int x){
        if(r==SIZE-1) return;
        if(f==-1) f=0;
        arr[++r]=x;
    }
    int pop(){
        int x=arr[f];
        if(f==r) f=r=-1;
        else f++;
        return x;
    }
    bool empty(){ return f==-1; }
    int size(){ return (f==-1?0:r-f+1); }
};

class Stack {
    Queue q;
public:
    void push(int x){
        q.push(x);
        int s = q.size()-1;
        while(s--){
            q.push(q.pop());
        }
    }
    int pop(){
        if(q.empty()) return -1;
        return q.pop();
    }
};

int main(){
    Stack s;
    s.push(5);
    s.push(9);
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
}
