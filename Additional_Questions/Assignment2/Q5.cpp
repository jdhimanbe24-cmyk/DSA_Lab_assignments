// Duplicate each occurrence of 2 in array
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100]; // assuming max size = 100
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result[100];
    int idx = 0;
    for (int i = 0; i < n && idx < n; i++) {
        result[idx++] = arr[i];
        if (arr[i] == 2 && idx < n) {
            result[idx++] = 2;
        }
    }

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) cout << result[i] << " ";
    cout << endl;
    return 0;
}
