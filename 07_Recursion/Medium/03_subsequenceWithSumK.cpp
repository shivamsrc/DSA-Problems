#include<bits/stdc++.h>
using namespace std;

// Count all subsequences with sum K
// Subsequence are same as a subset

void countSub(vector<int> &nums, int sum, int &cnt, int k, int i){
    if(i == nums.size()){
        if(sum == k) cnt++;
        return;
    }


    // no need to store each subsequence in a vector as we don't have to return all the subsequence
    
    // pick
    countSub(nums, (sum + nums[i]), cnt, k, i+1);

    // no need to pop as there is no vector storing them and also since the sum is passed by value so at this level the sum will be what we passed so no need to substract as well

    // not pick
    countSub(nums, sum, cnt, k, i+1);
}

int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    int cnt = 0;

    countSub(nums, 0, cnt, k, 0);

    return cnt;
}

int main(){
    vector<int> arr = {4, 9, 2, 5, 1};

    cout<<countSubsequenceWithTargetSum(arr, 10);

    return 0;
}