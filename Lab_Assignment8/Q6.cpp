#include <iostream>
using namespace std;

struct PriorityQueue {
    int arr[1000], size;
    bool maxHeap;
    PriorityQueue(bool maxH=true): size(0), maxHeap(maxH) {}

    void insert(int val) {
        arr[size++] = val;
        int i = size-1;
        while(i>0) {
            int p = (i-1)/2;
            if ((maxHeap && arr[p]>=arr[i]) || (!maxHeap && arr[p]<=arr[i])) break;
            swap(arr[i], arr[p]);
            i = p;
        }
    }

    int extract() {
        if(size==0) return -1;
        int top = arr[0];
        arr[0] = arr[--size];
        int i=0;
        while(true) {
            int l=2*i+1, r=2*i+2, extreme=i;
            if(maxHeap) {
                if(l<size && arr[l]>arr[extreme]) extreme=l;
                if(r<size && arr[r]>arr[extreme]) extreme=r;
            } else {
                if(l<size && arr[l]<arr[extreme]) extreme=l;
                if(r<size && arr[r]<arr[extreme]) extreme=r;
            }
            if(extreme!=i) { swap(arr[i], arr[extreme]); i=extreme; }
            else break;
        }
        return top;
    }
};

int main() {
    PriorityQueue pq(true); // max-heap
    pq.insert(10); pq.insert(5); pq.insert(20); pq.insert(1);

    cout << "Priority Queue extraction: ";
    int val;
    while((val=pq.extract())!=-1) cout<<val<<" ";
    cout << endl;
    return 0;
}
