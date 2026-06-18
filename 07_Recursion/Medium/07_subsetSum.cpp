#include<bits/stdc++.h>
using namespace std;

// Given an array nums of n integers. Return array of sum of all subsets of the array nums.
// considered that no duplicate elements in input array

void sum(vector<int>& nums, vector<int> &ans, int i, int sumVal){
    if(i==nums.size()){
        ans.push_back(sumVal);
        return;
    }

    //
    sum(nums, ans, i+1, sumVal+nums[i]);

    //
    sum(nums, ans, i+1, sumVal);
}

vector<int> subsetSums(vector<int>& nums) {
    vector<int> ans;
    int sumVal = 0;

    sum(nums, ans, 0, sumVal);

    return ans;
}

int main(){
    vector<int> arr = {5,2,1};

    vector<int> ans = subsetSums(arr);

    for(auto it : ans){
        cout<<it<<" ";
    }

    return 0;
}