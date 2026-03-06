#include<bits/stdc++.h>
using namespace std;

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// it's just lower_bound implementation

int searchInsert(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int ans;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low =  mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {1,3,5,6};

    cout<<searchInsert(arr, 5)<<endl;
    cout<<searchInsert(arr,2);

    return 0;
}