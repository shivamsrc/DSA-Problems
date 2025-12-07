#include<bits/stdc++.h>
using namespace std;

// generate all the permutations of a given set of elements 

void getPerms(vector<int>& nums, int ind, vector<vector<int>>& ans){
    if(ind == nums.size()){                                     // once all the positions are filled then we can push that combination of array to the ans vector
        ans.push_back(nums);
        return;
    }

    for(int i=ind; i<nums.size(); i++){                         // for every recursive call this loop will run that have the permutation of original array for the first 'i' as i=ind but then it will have different permuatations as well for the next one
        swap(nums[i], nums[ind]);
        getPerms(nums, ind+1, ans);
        swap(nums[i], nums[ind]);                              // backtracting - reverting the changes before going back to the previous level
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;

    getPerms(nums, 0, ans);
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};

    vector<vector<int>> result = permute(arr);

    for(auto it : result){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}