#include<bits/stdc++.h>
using namespace std;

// Find the smallest divisor given a threshold

// Brute
int totalSum(vector<int>& nums, int divisor){                       // it returns the sum of ceil of all elements divided by the divisor
    int n = nums.size();
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += (nums[i] + divisor -1) /divisor;
    }

    return sum;
}

int smallestDivisor2(vector<int>& nums, int threshold) {
    int n = nums.size();
    int maxi = *max_element(nums.begin(), nums.end());

    for(int i=1; i<=maxi; i++){
        long long sum = totalSum(nums, i);
        if(sum <= threshold) return i;
    }

    return -1;
}

// Optimal
int smallestDivisor(vector<int>& nums, int threshold){
    int n = nums.size();
    int maxi = *max_element(nums.begin(), nums.end());

    int low=1, high=maxi;
    int ans = maxi;

    while(low<=high){
        int mid = low + (high-low)/2;

        long long sum = totalSum(nums, mid);
        if(sum <= threshold){
            ans = mid;
            high = mid - 1;                                      // we got the answer but for minimum look in the left part
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {1,2,5,9};

    cout<<smallestDivisor(arr, 6);

    return 0;
}