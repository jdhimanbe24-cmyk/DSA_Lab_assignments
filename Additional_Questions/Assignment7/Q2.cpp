// Q2: Top K Frequent Elements
#include<iostream>
using namespace std;

struct Node {
    int val, freq;
};

void sortFreq(Node f[], int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(f[j].freq > f[i].freq ||
               (f[j].freq == f[i].freq && f[j].val > f[i].val)){
                    Node temp = f[i];
                    f[i] = f[j];
                    f[j] = temp;
               }
        }
    }
}

int main(){
    int a[] = {3,1,4,4,5,2,6,1};
    int n = 8, k = 2;

    int freq[1000]={0};
    for(int i=0;i<n;i++) freq[a[i]]++;

    Node f[1000];
    int size = 0;
    for(int i=0;i<1000;i++){
        if(freq[i]>0){
            f[size].val = i;
            f[size].freq = freq[i];
            size++;
        }
    }

    sortFreq(f,size);

    for(int i=0;i<k;i++) cout<<f[i].val<<" ";
}
