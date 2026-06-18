#include<bits/stdc++.h>
using namespace std;

// Print all subsets
void printSubset(vector<int> nums, vector<int> &ans, int i){
    if(i == nums.size()){
        for(int x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }

    // include choice
    ans.push_back(nums[i]);
    printSubset(nums, ans, i+1);

    // backtracking
    ans.pop_back();

    // exclude choice
    printSubset(nums, ans, i+1);
}

// return all subsets (LC 78)
void getSubsets(vector<int> nums, vector<int> &ans, int i, vector<vector<int>> &allSubs){
    if(i == nums.size()){
        allSubs.push_back(ans);
        return;
    }

    ans.push_back(nums[i]);
    getSubsets(nums, ans, i+1, allSubs);

    ans.pop_back();

    getSubsets(nums, ans, i+1, allSubs);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> allSubs;
    vector<int> ans;

    getSubsets(nums, ans, 0, allSubs);

    return allSubs;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<int> ans;

    printSubset(arr, ans, 0);


    return 0;
}