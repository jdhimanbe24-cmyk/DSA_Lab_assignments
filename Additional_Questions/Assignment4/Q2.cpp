// QUESTION 2: SORT QUEUE WITHOUT EXTRA SPACE

#include<iostream>
using namespace std;

#define SIZE 100

class Queue {
public:
    int arr[SIZE];
    int f, r;
    Queue() { f = r = -1; }

    bool empty() { return f == -1; }

    int size() { return empty() ? 0 : r - f + 1; }

    void push(int x) {
        if(r == SIZE-1) return;
        if(empty()) f = 0;
        arr[++r] = x;
    }

    int pop() {
        int x = arr[f];
        if(f == r) f = r = -1;
        else f++;
        return x;
    }

    int front() { return arr[f]; }
};

// Find index of minimum element in queue
int minIndex(Queue &q, int sortedIndex) {
    int min_val = 1e9, min_i = -1;
    int n = q.size();

    for(int i = 0; i < n; i++) {
        int curr = q.pop();
        if(curr < min_val && i <= sortedIndex) {
            min_val = curr;
            min_i = i;
        }
        q.push(curr);
    }
    return min_i;
}

// Move element at minIndex to rear
void moveToRear(Queue &q, int min_i) {
    int n = q.size();
    int min_val;

    for(int i = 0; i < n; i++) {
        int curr = q.pop();
        if(i == min_i) min_val = curr;
        else q.push(curr);
    }
    q.push(min_val);
}

void sortQueue(Queue &q) {
    for(int i = 1; i <= q.size(); i++) {
        int mi = minIndex(q, q.size() - i);
        moveToRear(q, mi);
    }
}

int main() {
    Queue q;
    int x;
    while(cin >> x) q.push(x);

    sortQueue(q);

    while(!q.empty()) cout << q.pop() << " ";
}
