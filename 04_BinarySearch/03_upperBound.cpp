#include<bits/stdc++.h>
using namespace std;

// Upper Bound - smallest index such that arr[ind]>target
// we can also use upper_bound method in C++

int ub(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {2,3,6,7,8,8,11,11,11,12};

    cout<<ub(arr,8)<<endl;

    cout<<upper_bound(arr.begin(), arr.end(), 8) - arr.begin();

    return 0;
}