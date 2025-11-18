// QUESTION 3: CHECK IF QUEUE CAN BE SORTED INTO ANOTHER QUEUE USING A STACK

#include<iostream>
using namespace std;

#define MAXN 1000

class Queue {
public:
    int a[MAXN];
    int f, r;
    Queue() { f = r = -1; }
    bool empty() const { return f == -1; }
    int size() const { return empty() ? 0 : (r - f + 1); }
    void push(int x) {
        if(r == MAXN-1) return; 
        if(empty()) f = 0;
        a[++r] = x;
    }
    int pop() {
        if(empty()) return -1;
        int x = a[f];
        if(f == r) f = r = -1;
        else f++;
        return x;
    }
    int front() const { return a[f]; }
};

class Stack {
public:
    int a[MAXN];
    int top;
    Stack() { top = -1; }
    bool empty() const { return top == -1; }
    void push(int x) { a[++top] = x; }
    int pop() { return a[top--]; }
    int peek() const { return a[top]; }
};

int main() {
    int n;
    if(!(cin >> n)) return 0;
    Queue q;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        q.push(x);
    }

    Stack s;
    int expected = 1;        
    while(!q.empty()) {
        if(q.front() == expected) {
            q.pop();
            expected++;
        } else if(!s.empty() && s.peek() == expected) {
            s.pop();
            expected++;
        } else {
          
            s.push(q.pop());
        }
    }

    
    while(!s.empty() && s.peek() == expected) {
        s.pop();
        expected++;
    }

    if(expected == n + 1) cout << "Yes";
    else cout << "No";

    return 0;
}
