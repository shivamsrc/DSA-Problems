#include<bits/stdc++.h>
using namespace std;

// Given the array nums (not neccessirly with distinct values) after the rotation and an integer target, return true if target is in nums, or false if it is not in nums

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return true;

        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low = low + 1;
            high = high - 1;
            continue;                           // skip everything below and start the next iteration
        }

        // left half is sorted
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        //right half is sorted
        else{
            if(nums[mid]<=target && target<=nums[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }

    return false;
}

int main(){
    vector<int> arr = {2,5,6,0,0,1,2};

    cout<<search(arr, 4);

    return 0;
}