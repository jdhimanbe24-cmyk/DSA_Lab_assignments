// Check if Two Arrays Are Equa
#include <iostream>
using namespace std;

bool arraysEqual(int a[], int b[], int n) {
    bool counted[n];
    for(int i=0;i<n;i++) counted[i]=false;

    for(int i=0;i<n;i++){
        bool found = false;
        for(int j=0;j<n;j++){
            if(!counted[j] && a[i]==b[j]){
                counted[j]=true;
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

int main() {
    int a[] = {1, 2, 5, 4, 0};
    int b[] = {2, 4, 5, 0, 1};
    int n = sizeof(a)/sizeof(a[0]);
    cout << (arraysEqual(a,b,n) ? "true" : "false") << endl;
    return 0;
}
