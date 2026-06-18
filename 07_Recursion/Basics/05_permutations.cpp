#include<bits/stdc++.h>
using namespace std;

// Permutations of an array - chech basic recursion notes

void getPerms(vector<int>& nums, int ind, vector<vector<int>> &ans){
    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=ind; i<nums.size(); i++){
        swap(nums[i], nums[ind]);
        getPerms(nums, ind+1, ans);
        swap(nums[i], nums[ind]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;

    getPerms(nums, 0, ans);

    return ans;
}

int main(){
    vector<int> arr = {1,2,3};

    vector<vector<int>> ans = permute(arr);

    for(auto it : ans){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}