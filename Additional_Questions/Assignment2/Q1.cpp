// Find pairs with difference K
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];  // assuming max size = 100
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter k: ";
    cin >> k;

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k) {
                count++;
            }
        }
    }

    cout << "Count of pairs: " << count << endl;
    return 0;
}