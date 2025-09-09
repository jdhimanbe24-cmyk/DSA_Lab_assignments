// Design Stack with getMin() in O(1)
#include <iostream>
using namespace std;

int stackArr[100], topIndex = -1, minVal;

void push(int x) {
    if (topIndex == -1) {
        minVal = x;
        stackArr[++topIndex] = x;
    } else if (x >= minVal) {
        stackArr[++topIndex] = x;
    } else {
        stackArr[++topIndex] = 2 * x - minVal;
        minVal = x;
    }
}

void pop() {
    if (topIndex == -1) return;
    int t = stackArr[topIndex--];
    if (t < minVal) {
        minVal = 2 * minVal - t;
    }
}

int peek() {
    int t = stackArr[topIndex];
    if (t >= minVal) return t;
    return minVal;
}

int getMin() {
    return minVal;
}

int main() {
    push(2);
    push(3);
    cout << peek() << " ";  // 3
    pop();
    cout << getMin() << " "; // 2
    push(1);
    cout << getMin() << endl; // 1
    return 0;
}
