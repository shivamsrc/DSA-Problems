#include<bits/stdc++.h>
using namespace std;

// Split Array Largest Sum - Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.
bool possible(vector<int>& nums, int m, int maxSum){
    int n = nums.size();
    int maxiCounter = 0;
    int partition = m;

    for(int i=0; i<n; i++){
        if(maxiCounter + nums[i] > maxSum){
            partition--;
            maxiCounter = 0;
        }
        maxiCounter += nums[i];
    }
    partition--;

    return partition<0 ? false : true;
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(possible(nums, k, mid)==true){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {7,2,5,10,8};

    cout<<splitArray(arr,2);

    return 0;
}