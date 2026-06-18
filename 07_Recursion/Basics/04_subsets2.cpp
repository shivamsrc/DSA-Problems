#include<bits/stdc++.h>
using namespace std;

// return all unique subsets of array having duplicate elements (LC 90)

void getSubsets(vector<int> nums, vector<int> &ans, int i, vector<vector<int>> &allSubs){
    if(i == nums.size()){
        allSubs.push_back(ans);
        return;
    }

    ans.push_back(nums[i]);
    getSubsets(nums, ans, i+1, allSubs);

    ans.pop_back();

    int idx = i+1;
    while(idx < nums.size() && nums[idx] == nums[idx-1]){           // After popping, if we call recursion for the next identical element, it would create the same exclusion decision again and generate duplicate subsets (just removed the same element with pop that we'll include). So we jump to the next different element
        idx++;
    }

    getSubsets(nums, ans, idx, allSubs);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<int> ans;
    vector<vector<int>> allSubs;

    getSubsets(nums, ans, 0, allSubs);

    return allSubs;
}

int main(){
    vector<int> arr = {1,2,2
    };

    vector<vector<int>> ans = subsetsWithDup(arr);

    for(auto it : ans){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}