#include<bits/stdc++.h>
using namespace std;

// Combination Sum (LC 39)

set<vector<int>> st;                                                // for unique combinations

void combination(vector<int> &arr, vector<vector<int>> &ans, int i, int target, vector<int> &comb){

    if(target == 0 && st.find(comb) == st.end()){
        ans.push_back(comb);
        st.insert(comb);
        return;
    } 

    if(i==arr.size() || target < 0) return;


    comb.push_back(arr[i]);

    combination(arr, ans, i+1, target-arr[i], comb);            // single inclusion

    combination(arr, ans, i, target-arr[i], comb);              // multiple inclusion

    comb.pop_back();                                            // backtrack

    combination(arr, ans, i+1, target, comb);            // exclusion
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> comb;

    combination(arr, ans, 0, target, comb);

    return ans;
}

int main(){
    vector<int> arr = {2,3,5};

    vector<vector<int>> ans = combinationSum(arr, 8);

    for(auto it : ans){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }


    return 0;
}