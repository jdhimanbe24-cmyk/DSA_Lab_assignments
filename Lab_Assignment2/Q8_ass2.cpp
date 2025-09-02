#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i=0;i<n;i++) cin >> arr[i];

    unordered_set<int> s;
    for(int i=0;i<n;i++) s.insert(arr[i]);

    cout << "Distinct count: " << s.size() << endl;
}
