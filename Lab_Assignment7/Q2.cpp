// Q2: Improved Selection Sort (Min & Max in every pass)
#include<iostream>
using namespace std;

void improvedSelectionSort(int a[], int n){
    int left = 0, right = n-1;

    while(left < right){
        int minIdx = left, maxIdx = right;

        for(int i = left; i <= right; i++){
            if(a[i] < a[minIdx]) minIdx = i;
            if(a[i] > a[maxIdx]) maxIdx = i;
        }

        swap(a[left], a[minIdx]);

        if(maxIdx == left) maxIdx = minIdx;

        swap(a[right], a[maxIdx]);

        left++;
        right--;
    }
}

void printArr(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

int main(){
    int a[] = {7,1,9,3,5,8,2};
    int n = 7;

    improvedSelectionSort(a,n);
    printArr(a,n);
}
