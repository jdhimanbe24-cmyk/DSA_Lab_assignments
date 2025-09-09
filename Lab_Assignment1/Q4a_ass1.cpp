//reverse element of an array 
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n/2; i++)
        swap(arr[i], arr[n-i-1]);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;

}
