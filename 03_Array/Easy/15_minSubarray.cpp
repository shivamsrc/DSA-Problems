#include<bits/stdc++.h>
using namespace std;

// Given an array of positive integers nums and a positive integer target.
// return the minimal length of a subarray whose sum is greater than or equal to target. 
// If there is no such subarray, return 0 instead.

// same as the optimal of last one.

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int minLen = INT_MAX;

    for(int right = 0; right<n; right++){
        sum = sum + nums[right];

        while(sum >= target){                                     // if sum is bigger than the target then reduce the sum in way that it remains equal or greater than the target with the smaller subArray length.
            minLen = min(minLen, right-left+1);
            sum = sum - nums[left];
            left++;
        }
    }

    return {minLen == INT_MAX ? 0 : minLen};
}

int main(){
    vector<int> arr = {1,2,3,1,7,2,3,4};

    cout<<minSubArrayLen(9,arr);

    return 0;
}