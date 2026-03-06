#include<bits/stdc++.h>
using namespace std;

// Find peak element

// Brute 
int findPeakElement3(vector<int>& nums) {
    int n = nums.size();

    for(int i=0; i<n; i++){
        if((i==0 || nums[i-1]<nums[i]) && (i==n-1 || nums[i+1]<nums[i])) return i;
    }

    return -1;
}

// Optimal

// array with one peak
int findPeakElement2(vector<int>& nums){
    int n = nums.size();
    if(n==1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;
    int low=1, high=n-2;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

        else if(nums[mid] < nums[mid+1]){                                // we're in the left half where the curve is rising
            low = mid + 1;
        }
        else if(nums[mid] > nums[mid+1]){                               // right half where we've falling curve
            high = mid - 1;
        }
    }

    return -1;
}

// array with multiple peak
int findPeakElement(vector<int>& nums){
    int n = nums.size();
    if(n==1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;
    int low=1, high=n-2;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

        else if(nums[mid] < nums[mid+1]){                                // we're in the left half where the curve is rising
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {1,2,1,3,5,6,4};

    cout<<findPeakElement(arr);

    return 0;
}