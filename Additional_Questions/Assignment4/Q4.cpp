// QUESTION 4: NUMBER OF STUDENTS UNABLE TO EAT LUNCH

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

int main() {
    int n;
    if(!(cin >> n)) return 0;

    Queue students;
    for(int i = 0; i < n; ++i) {
        int s; cin >> s;
        students.push(s);
    }
 
    int sandwiches[MAXN];
    for(int i = 0; i < n; ++i) cin >> sandwiches[i];

    int topIndex = 0;              
    int rotations = 0;             
    while(topIndex < n && !students.empty() && rotations < students.size()) {
        if(students.front() == sandwiches[topIndex]) {
        
            students.pop();
            topIndex++;
            rotations = 0;          
        } else {

            int tmp = students.pop();
            students.push(tmp);
            rotations++;
        }
        
    }

    cout << students.size();
    return 0;
}
