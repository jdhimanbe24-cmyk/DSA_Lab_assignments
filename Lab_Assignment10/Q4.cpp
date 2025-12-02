// First non-repeating element
#include <iostream>
using namespace std;

int firstNonRepeating(int nums[], int n) {
    for(int i=0;i<n;i++){
        bool repeated = false;
        for(int j=0;j<n;j++){
            if(i!=j && nums[i]==nums[j]){
                repeated = true;
                break;
            }
        }
        if(!repeated) return nums[i];
    }
    return -1;
}

int main() {
    int nums[] = {4,5,1,2,0,4};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "First non-repeating element: " << firstNonRepeating(nums,n) << endl;
    return 0;
}
