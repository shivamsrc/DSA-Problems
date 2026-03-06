#include<bits/stdc++.h>
using namespace std;

// Floor - largest no. in array <= target
// Ceil - smallest no. in array >= target (similar to lower bound)

int floorVal(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] <= target){                             // if nums[mid] <= target then nums[mid] can be the floor value but we'll check if any other element larger than ans but smaller than target exists or not.
            ans = nums[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {3,4,4,7,9};

    cout<<floorVal(arr,8);

    return 0;
}