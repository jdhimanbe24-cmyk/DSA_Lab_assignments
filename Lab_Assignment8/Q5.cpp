#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool maxHeap=true) {
    int extreme = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (maxHeap) {
        if (l<n && arr[l]>arr[extreme]) extreme=l;
        if (r<n && arr[r]>arr[extreme]) extreme=r;
    } else {
        if (l<n && arr[l]<arr[extreme]) extreme=l;
        if (r<n && arr[r]<arr[extreme]) extreme=r;
    }
    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, maxHeap);
    }
}

void heapSort(int arr[], int n, bool increasing=true) {
    for (int i=n/2-1;i>=0;i--) heapify(arr,n,i,increasing);
    for (int i=n-1;i>0;i--) {
        swap(arr[0], arr[i]);
        heapify(arr,i,0,increasing);
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;

    heapSort(arr,n,true);
    cout << "Increasing: "; for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;

    heapSort(arr,n,false);
    cout << "Decreasing: "; for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
    return 0;
}
