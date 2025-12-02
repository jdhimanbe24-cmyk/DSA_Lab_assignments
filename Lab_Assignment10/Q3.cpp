// Count frequency of each number
#include <iostream>
using namespace std;

void countFrequency(int nums[], int n) {
    bool counted[n];
    for(int i=0;i<n;i++) counted[i]=false;

    for(int i=0;i<n;i++){
        if(counted[i]) continue;
        int count=1;
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j]){
                count++;
                counted[j]=true;
            }
        }
        cout << nums[i] << " → " << count << " times" << endl;
    }
}

int main() {
    int nums[] = {2,3,2,4,3,2};
    int n = sizeof(nums)/sizeof(nums[0]);
    countFrequency(nums,n);
    return 0;
}
