// Check if A -> B sorted using stack
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int A[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    int stackArr[100], top = -1;
    int expected = 1; // assuming we want sorted ascending from 1,2,3...N
    for (int i = 0; i < n; i++) {
        stackArr[++top] = A[i];
        while (top >= 0 && stackArr[top] == expected) {
            top--;
            expected++;
        }
    }

    if (top == -1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
