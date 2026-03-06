#include<bits/stdc++.h>
using namespace std;

// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k. Return the kth positive integer that is missing from this array.

// Brute
int findKthPositive2(vector<int>& arr, int k) {
    int n = arr.size();
    int ans = k;                                         // we assume that no number is missin so the kth required number is k itself

    for(int i=0; i<n; i++){
        if(arr[i]<=ans){
            ans++;                                      // Every time we see a number in arr that is ≤ current ans, it means: One missing number we counted is actually present in the array. So we need to "shift" our answer forward.
        }
        else{
            break;
        }
    }

    return ans;
}

// Optimal
int findKthPositive(vector<int>& arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans;

    while(low<=high){
        int mid = low + (high-low)/2;

        int missing = arr[mid] - (mid+1);

        if(missing<k) low = mid + 1;
        else high = mid - 1;
    }

    return k + high + 1;
}

int main(){
    vector<int> arr = {2,3,4,7,11};

    cout<<findKthPositive(arr, 5);

    return 0;
}