// Q1: Sorting Techniques
#include<iostream>
using namespace std;

// Selection Sort
void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[minIdx]) minIdx=j;
        swap(a[i],a[minIdx]);
    }
}

// Insertion Sort
void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

// Bubble Sort
void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

// Merge Sort Helpers
void merge(int a[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int *L = new int[n1];
    int *R = new int[n2];

    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }

    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

// Quick Sort Helpers
int partitionIndex(int a[], int low, int high){
    int pivot = a[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high){
    if(low<high){
        int p = partitionIndex(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

void printArray(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

int main(){
    int a[] = {5,3,8,4,2};
    int n = 5;

    cout<<"Selection Sort: ";
    int s1[5]={5,3,8,4,2};
    selectionSort(s1,n);
    printArray(s1,n);

    cout<<"Insertion Sort: ";
    int s2[5]={5,3,8,4,2};
    insertionSort(s2,n);
    printArray(s2,n);

    cout<<"Bubble Sort: ";
    int s3[5]={5,3,8,4,2};
    bubbleSort(s3,n);
    printArray(s3,n);

    cout<<"Merge Sort: ";
    int s4[5]={5,3,8,4,2};
    mergeSort(s4,0,n-1);
    printArray(s4,n);

    cout<<"Quick Sort: ";
    int s5[5]={5,3,8,4,2};
    quickSort(s5,0,n-1);
    printArray(s5,n);
}
