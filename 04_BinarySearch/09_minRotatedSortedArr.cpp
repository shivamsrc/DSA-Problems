#include<bits/stdc++.h>
using namespace std;

// Find minimum in rotated sorted array

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = INT_MAX;

    while(low<=high){
        int mid = low + (high-low)/2;

        // left half is sorted
        if(nums[low]<=nums[mid]){
            ans = min(nums[low], ans);
            low = mid + 1;                                   // eliminating this half
        }
        // right half is sorted
        else{
            ans = min(nums[mid], ans);
            high = mid-1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};

    cout<<findMin(arr);

    return 0;
}