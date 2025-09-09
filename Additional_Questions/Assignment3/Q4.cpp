// Daily Temperatures
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[100], ans[100];
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                ans[i] = j - i;
                break;
            }
        }
    }

    cout << "Output: ";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
