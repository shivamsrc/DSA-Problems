#include<bits/stdc++.h>
using namespace std;

// Check if there exists a subsequence with sum K

bool checker(vector<int> nums, int k, int sum, int i){
    if(i == nums.size()){
        return sum == k;
    }

    // pick
    if(checker(nums, k, sum+nums[i], i+1)){
        return true;
    }

    // not pick
    if(checker(nums, k, sum, i+1)){
        return true;
    }

    return false;
}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    bool ans = checker(nums, k, 0, 0);

    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    cout<<checkSubsequenceSum(arr, 8);

    return 0;
}