#include<bits/stdc++.h>
using namespace std;

// Find single element in sorted array where every element appears exactly twice except one element that appears exactly once.

// Brute
int singleNonDuplicate2(vector<int>& nums) {
    int n = nums.size();
    int ans = -1;

    for(int i=0; i<n; i++){
        if(i==0){
            if(nums[i] != nums[i+1]){
                ans = nums[i];
                return ans;
            };
        }
        else if(i==n-1){
            if(nums[i] != nums[i-1]){
                ans = nums[i];
                return ans;
            }
        }
        else{
            if(nums[i] != nums[i+1] && nums[i] != nums[i-1]){
                ans = nums[i];
                return ans;
            }
        }
    }

    return ans;
}

// Optimal - BS
int singleNonDuplicate(vector<int>& nums){
    int n = nums.size();
    
    if(n==1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];

    int low = 1, high = n-2;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

        // we are in the left half
        // if we're in the left half : (even, odd) - if mid is even check with mid+1 which is odd and if mid is odd then check for mid-1 which is even
        if((mid%2 == 0 && nums[mid]==nums[mid+1]) || (mid%2 == 1 && nums[mid]==nums[mid-1])){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {1,1,2,3,3,4,4,5,5};

    cout<<singleNonDuplicate(arr);

    return 0;
}