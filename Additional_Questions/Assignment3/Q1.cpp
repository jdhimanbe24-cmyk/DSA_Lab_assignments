// Nearest Smaller Element
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[100], ans[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int smaller = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                smaller = arr[j];
                break;
            }
        }
        ans[i] = smaller;
    }

    cout << "Output: ";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}