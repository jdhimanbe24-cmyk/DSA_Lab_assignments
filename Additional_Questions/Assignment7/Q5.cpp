// Q5: Maximum Ice Cream Bars using Counting Sort
#include<iostream>
using namespace std;

int main(){
    int costs[] = {1,6,3,1,2,5};
    int n = 6, coins = 20;

    int freq[10001]={0};
    int maxCost = 0;

    for(int i=0;i<n;i++){
        freq[costs[i]]++;
        if(costs[i] > maxCost) maxCost = costs[i];
    }

    int count = 0;
    for(int cost=1; cost<=maxCost; cost++){
        while(freq[cost] > 0 && coins >= cost){
            coins -= cost;
            count++;
            freq[cost]--;
        }
    }

    cout << count;
}
