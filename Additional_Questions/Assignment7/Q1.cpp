// Q1: Majority Element
#include<iostream>
using namespace std;

int majorityElement(int a[], int n){
    int cand = 0, count = 0;
    for(int i=0;i<n;i++){
        if(count==0) cand = a[i];
        count += (a[i]==cand ? 1 : -1);
    }
    return cand;
}

int main(){
    int a[] = {2,2,1,1,1,2,2};
    int n = 7;
    cout << majorityElement(a,n);
}
