#include<bits/stdc++.h>
using namespace std;

// lower bound - smallest index such that arr[ind] >= x
// we can also use lower_bound method in C++

int lb(vector<int>& nums, int target){
    int n = nums.size();
    int ans = n;                                 // default - if there isn't any lower bound then the hypothetical last index will be considered as the lb

    int low = 0, high = n-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 10, 20, 30, 40, 50};

    cout<<lb(arr, 35);

    cout<<endl;

    cout<<lower_bound(arr.begin(), arr.end()-1, 35) - arr.begin();                // both values are iterators (i.e, lower_bound and arr.begin) pointing to certain value. Iterators are mainly the address so by substracting them and dividing by the size of one int element we can find the index and that's what's happeing here

    return 0;
}