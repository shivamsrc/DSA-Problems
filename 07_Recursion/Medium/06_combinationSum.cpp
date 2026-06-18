#include<bits/stdc++.h>
using namespace std;

// Combination Sum (LC 40)

void combination(vector<int> &arr, vector<vector<int>> &ans, vector<int> &comb, int i, int target){
    if(target == 0){
        ans.push_back(comb);
        return;
    }

    if(i==arr.size() || target < 0) return;

    // inclusion
    comb.push_back(arr[i]);
    combination(arr, ans, comb, i+1, target-arr[i]);
    
    // exclusion
    comb.pop_back();

    // making sure that the next element isn't the same as the previous one because we just exluded it ans if we include the same element again, theexlusion will have no value.
    int idx = i+1;
    while(idx < arr.size() && arr[idx] == arr[idx-1]){
        idx++;
    }

    combination(arr, ans, comb, idx, target);
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> comb;
    sort(arr.begin(), arr.end());

    combination(arr, ans, comb, 0, target);

    return ans;
}

int main(){
    vector<int> arr = {10,1,2,7,6,1,5};

    vector<vector<int>> ans = combinationSum2(arr, 8);

    for(auto it : ans){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}