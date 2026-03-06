#include<bits/stdc++.h>
using namespace std;

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// Linear Search - Brute

// Binary Search
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;

        // check if the left half is sorted
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){                  // target lies in the left half
                high = mid - 1;
            }
            else {
                low = mid+1;
            }
        }
        // right half is sorted
        else{
            if(target >= nums[mid] && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};

    cout<<search(arr, 0);

    return 0;
}