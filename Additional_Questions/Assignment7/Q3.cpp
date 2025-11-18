// Q3: Maximum Sum Combination
#include<iostream>
using namespace std;

void sortDesc(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j] > a[i]){
                int t=a[i]; a[i]=a[j]; a[j]=t;
            }
        }
    }
}

int main(){
    int A[] = {1,4,2,3};
    int B[] = {2,5,1,6};
    int n = 4, k = 3;

    int all[100];
    int idx=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            all[idx++] = A[i] + B[j];

    sortDesc(all,idx);

    for(int i=0;i<k;i++)
        cout<<all[i]<<" ";
}
