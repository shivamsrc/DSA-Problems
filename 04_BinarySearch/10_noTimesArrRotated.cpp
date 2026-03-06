#include<bits/stdc++.h>
using namespace std;

// Find out how many times array has been rotated
// If right rotated 'k' times, minimum element index = k
// so just find the min element index

int findKRotation(vector<int> &nums) {
    int n = nums.size();
    int low = 0, high = n-1;\
    int ans = INT_MAX;
    int ansInd = 0;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[low]<=nums[mid]){
            if(nums[low]<ans){
                ans = nums[low];
                ansInd = low;
            }
            low = mid + 1;
        }
        else{
            if(nums[mid]<ans){
                ans = nums[mid];
                ansInd = mid;
            }
            high = mid - 1;
        }
    }

    return ansInd;
}

int main(){
    vector<int> arr = {3,4,5,1,2};

    cout<<findKRotation(arr);

    return 0;
}