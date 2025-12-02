// Most Frequent Element (Return Largest if Tie)
#include <iostream>
using namespace std;

int mostFrequent(int arr[], int n) {
    int maxFreq = 0;
    int result = arr[0];
    for(int i=0;i<n;i++){
        int count = 1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]) count++;
        }
        if(count > maxFreq || (count==maxFreq && arr[i]>result)){
            maxFreq = count;
            result = arr[i];
        }
    }
    return result;
}

int main() {
    int arr[] = {1, 2, 2, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Most Frequent Element: " << mostFrequent(arr,n) << endl;
    return 0;
}
