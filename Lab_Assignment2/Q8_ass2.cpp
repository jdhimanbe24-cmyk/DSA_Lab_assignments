// to count total number of distinct elements in an array of length n.
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int distinct = 0;  // counter for distinct elements
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        // check if arr[i] appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) distinct++;
    }

    cout << "Distinct count: " << distinct << endl;
    return 0;
}
