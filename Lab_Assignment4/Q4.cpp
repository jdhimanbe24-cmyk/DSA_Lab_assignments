// QUESTION 4: FIRST NON-REPEATING CHARACTER USING QUEUE

#include<iostream>
using namespace std;

#define SIZE 50

class Queue {
public:
    char arr[SIZE];
    int f, r;
    Queue(){ f = r = -1; }

    void push(char c){
        if(r == SIZE-1) return;
        if(f == -1) f = 0;
        arr[++r] = c;
    }
    void pop(){
        if(f == -1) return;
        if(f == r) f = r = -1;
        else f++;
    }
    char front(){ return arr[f]; }
    bool empty(){ return f == -1; }
};

int main() {
    char c;
    int freq[256] = {0};
    Queue q;

    while(cin>>c) {
        freq[c]++;
        q.push(c);

        while(!q.empty() && freq[q.front()] > 1)
            q.pop();

        if(q.empty()) cout<<"-1 ";
        else cout<<q.front()<<" ";
    }
}
