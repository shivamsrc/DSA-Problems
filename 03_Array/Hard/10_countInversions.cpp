#include<bits/stdc++.h>
using namespace std;

// Count Inversions
// Given an array, return the count of pairs {a[i], a[j]} where a[i]>a[j] and i<j

// Brute
long long int numberOfInversions(vector<int> nums) {
    int n = nums.size();
    long long int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i]>nums[j]) cnt++;
        }
    }

    return cnt;
}

// Optimal - using merge sort

int merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int cnt = 0;

    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        // left > right means (left,right)
        else{
            temp.push_back(arr[right]);
            right++;
            cnt = cnt + (mid-left+1);                             /* count inversion */
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }

    return cnt;
}

int mS(vector<int>& arr, int low, int high){                            // divide the array in left and right part
    int cnt = 0;
    if(low >= high) return cnt;

    int mid = (low+high)/2;
    cnt += mS(arr, low, mid);                                                 // further division of left part into left and right
    cnt += mS(arr, mid+1, high);                                              // // further division of right part into left and right
    cnt += merge(arr, low, mid, high);

    return cnt;
}

int mergeSort(vector<int>& arr, int n){
    return mS(arr, 0, n-1);
}

long long int numberOfInversions2(vector<int>& arr){
    int n = arr.size();
    return mergeSort(arr, n);
}

int main(){
    vector<int> arr = {5,3,2,4,1};

    cout<<numberOfInversions2(arr);

    return 0;
}