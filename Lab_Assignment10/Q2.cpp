// Find common elements in two arrays
#include <iostream>
using namespace std;

void commonElements(int A[], int B[], int n, int m) {
    cout << "Common elements: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i]==B[j]){
                cout << A[i] << " ";
                break; // avoid duplicates
            }
        }
    }
    cout << endl;
}

int main() {
    int A[] = {1,2,3,4};
    int B[] = {3,4,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    commonElements(A,B,n,m);
    return 0;
}
