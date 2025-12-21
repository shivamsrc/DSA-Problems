#include<bits/stdc++.h>
using namespace std;

// Reverse Pair
// Similar to count inversion but here the condition for pair (a,b) is that a > 2*b

// Brute
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] > (2 * nums[j])){
                cnt++;
            }
        }
    }

    return cnt;
}

// Optimal

void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;

    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
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

}

int countPair(vector<int>& arr, int low, int mid, int high){                // checking possible pairs from two sorted array
    int right = mid+1;
    int cnt = 0;

    for(int i=low; i<=mid; i++){
        while(right <= high && (long long)arr[i] > 2LL*arr[right]) right++;
        cnt = cnt + (right - (mid+1));                                    // in the right array, all the element from (mid+1 to right) can form pair so that's the count for the arr[left]
    }

    return cnt;
}

int mS(vector<int>& arr, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;

    int mid = (low+high)/2;

    cnt += mS(arr, low, mid);
    cnt += mS(arr, mid+1, high);
    cnt += countPair(arr, low, mid, high);
    merge(arr, low, mid, high);

    return cnt;
}

int mergeSort(vector<int>& arr, int n){
    return mS(arr, 0, n-1);
}

int reversePairs2(vector<int>& nums){
    int n = nums.size();

    return mergeSort(nums, n);
}

int main(){
    vector<int> arr = {2,4,3,5,1};

    cout<<reversePairs2(arr);

    return 0;
}