// Evaluation of postfix expression
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
};

int evaluatePostfix(string exp) {
    Stack st;
    for (char c : exp) {
        if (isdigit(c)) st.push(c - '0'); // convert char to int
        else {
            int val2 = st.pop();
            int val1 = st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.pop();
}

int main() {
    string exp;
    cout << "Enter postfix: ";
    cin >> exp;
    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}