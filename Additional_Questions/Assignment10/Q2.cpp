// Check if Pair Sum Equals Target
#include <iostream>
using namespace std;

bool hasPairWithSum(int arr[], int n, int target) {
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target) return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = -2;
    cout << (hasPairWithSum(arr,n,target) ? "true" : "false") << endl;
    return 0;
}
