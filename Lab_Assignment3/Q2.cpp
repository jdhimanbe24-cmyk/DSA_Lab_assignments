// Reverse a string using stack
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class CharStack {
    char arr[MAX];
    int top;
public:
    CharStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    CharStack st;
    for (char c : s) st.push(c);

    string rev = "";
    while (!st.isEmpty()) rev += st.pop();

    cout << "Reversed: " << rev << endl;
    return 0;
}
