// QUESTION 1: GENERATE BINARY NUMBERS FROM 1 TO n

#include<iostream>
using namespace std;

#define SIZE 1000

class Queue {
public:
    string arr[SIZE];
    int f, r;
    Queue() { f = r = -1; }

    bool empty() { return f == -1; }

    void push(string s) {
        if(r == SIZE-1) return;
        if(empty()) f = 0;
        arr[++r] = s;
    }

    string pop() {
        string x = arr[f];
        if(f == r) f = r = -1;
        else f++;
        return x;
    }
};

int main() {
    int n; 
    cin >> n;

    Queue q;
    q.push("1");

    for(int i = 1; i <= n; i++) {
        string s1 = q.pop();
        cout << s1;

        if(i != n) cout << ", ";

        q.push(s1 + "0");
        q.push(s1 + "1");
    }
}
