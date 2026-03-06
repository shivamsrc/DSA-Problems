#include<bits/stdc++.h>
using namespace std;

// Allocate books to students in such a way that the max no. of pages allocated is min
bool possible(vector<int>& nums, int m, int maxAlloc){
    int n = nums.size();
    int maxiCounter = 0;
    int students = m;

    for(int i=0; i<n; i++){
        if(maxiCounter + nums[i] > maxAlloc){
            students--;
            maxiCounter = 0;
        }
        maxiCounter += nums[i];
    }
    students--;

    return students<0 ? false : true;
}

int findPages(vector<int> &nums, int m)  {
    int n = nums.size();
    if(m>n) return -1;
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(possible(nums, m, mid) == true){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;

}

int main(){
    vector<int> arr = {12,34,67, 90};

    cout<<findPages(arr, 2);

    return 0;
}