// Q4: Sort even-placed increasing, odd-placed decreasing
#include<iostream>
using namespace std;

void sortInc(int a[], int n){
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[j] < a[i]) swap(a[j],a[i]);
}

void sortDec(int a[], int n){
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[j] > a[i]) swap(a[j],a[i]);
}

int main(){
    int a[] = {0,1,2,3,4,5,6,7};
    int n = 8;

    int even[100], odd[100];
    int e=0, o=0;

    for(int i=0;i<n;i++){
        if(i%2==0) even[e++] = a[i];
        else odd[o++] = a[i];
    }

    sortInc(even,e);
    sortDec(odd,o);

    for(int i=0;i<e;i++) cout<<even[i]<<" ";
    for(int i=0;i<o;i++) cout<<odd[i]<<" ";
}
