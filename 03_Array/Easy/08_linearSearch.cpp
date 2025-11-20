#include<bits/stdc++.h>
using namespace std;

// return the index of first occurance of any given number
int linearSearch(vector<int>& nums, int k){
    int n = nums.size();

    for(int i=0; i<n; i++){
        if(nums[i] == k){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {10, 2, 4, 8, 22, -100, -42, 9};

    cout<<linearSearch(arr, -42);

    return 0;
}