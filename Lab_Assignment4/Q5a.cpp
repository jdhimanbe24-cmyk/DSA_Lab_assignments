// QUESTION 5(a): STACK USING TWO QUEUES

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
};

class Stack {
    Queue q1, q2;
public:
    void push(int x){
        q2.push(x);
        while(!q1.empty())
            q2.push(q1.pop());
        Queue t = q1;
        q1 = q2;
        q2 = t;
    }
    int pop(){
        if(q1.empty()) return -1;
        return q1.pop();
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    cout<<s.pop()<<" "; 
    cout<<s.pop()<<" ";
}
