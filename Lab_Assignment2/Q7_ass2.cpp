// to find number of inversions in an array.
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] > arr[j]) count++;
    cout << "Number of inversions: " << count << endl;
}

