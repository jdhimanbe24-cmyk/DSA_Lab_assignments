// Check if array contains duplicates
#include <iostream>
using namespace std;

bool containsDuplicate(int nums[], int n) {
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(nums[i]==nums[j]) return true;
    return false;
}

int main() {
    int nums[] = {1,2,3,1};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << (containsDuplicate(nums,n) ? "true" : "false") << endl;
    return 0;
}
