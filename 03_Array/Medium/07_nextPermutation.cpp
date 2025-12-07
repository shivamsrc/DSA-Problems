#include<bits/stdc++.h>
using namespace std;

// Next permutation

// Brute

// Better
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

// Optimal
void nextPermutation2(vector<int>& nums){
    int n = nums.size();
    int ind = -1;

    // finding break point
    for(int i=n-2; i>=0; i--){                                        // as the last element can't be the break point so starting from the 2nd last element
        if(nums[i] < nums[i+1]){
            ind = i;
            break;
        }
    }

    // if no break point found means it's the largest permutation so need to reverse the smallest permutation
    if(ind == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // swaping the break point element with the smallest element right of the break point (but that should be greater than the break point element)
    for(int i=n-1; i>ind; i--){
        if(nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }
    }

    reverse(nums.begin() + ind + 1, nums.end());
}

int main(){
    vector<int> arr = {2,1,5,4,3,0,0};

    nextPermutation2(arr);

    for(auto it : arr){
        cout<<it<<" ";
    }

    return 0;
}