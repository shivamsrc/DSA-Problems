#include<bits/stdc++.h>
using namespace std;

// Combination Sum III (LC 216) --> Find all valid combinations of k numbers (k reprsents the number of elements that should be there in the combination) that sum up to (target) such that the following conditions are true: Only numbers 1 to 9 are used. Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

void combination(vector<vector<int>> &ans, vector<int> &comb, int k, int target, int n){
    if(target == 0 && comb.size()==k){
        ans.push_back(comb);
        return;
    }

    if(target < 0 || n==10 || comb.size() > k) return;

    //
    comb.push_back(n);
    combination(ans, comb, k, target-n, n+1);

    //
    comb.pop_back();
    combination(ans, comb, k, target, n+1);
}

vector<vector<int>> combinationSum3(int k, int target) {
    vector<vector<int>> ans;
    vector<int> comb;

    combination(ans, comb, k, target, 1);

    return ans;
}

int main(){
    vector<vector<int>> ans = combinationSum3(3,9);

    for(auto it : ans){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}