#include<bits/stdc++.h>
using namespace std;

// Binary Search
// return the index of given target if exists else return -1

// Iterative method
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = floor((low+high)/2);

        if(target == nums[mid]) return mid;

        else if(target > nums[mid]){               // target lies in the right half
            low = mid + 1;
        }

        else{                                      // target lies in the left half
            high = mid - 1;
        }
    }

    return -1;
}

// Recursive method
int bs(vector<int>& nums, int low, int high, int target){
    if(low > high) return -1;                     // base condition

    int mid = floor((low+high)/2);

    if(target == nums[mid]) return mid;

    else if(target > nums[mid]){
        return bs(nums, mid+1, high, target);
    }

    else return bs(nums, low, mid-1, target);
}

int search2(vector<int>& nums, int target){
    int n = nums.size();
    return bs(nums, 0, n-1, target);
}

int main(){
    vector<int> arr = {-1,0,3,5,9,12};

    cout<<search2(arr, 9);

    return 0;
}