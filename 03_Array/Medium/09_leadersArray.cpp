#include<bits/stdc++.h>
using namespace std;

// Leaders in an array
// Everything to the right should be smaller

// Brute
vector<int> leaders(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;

    for(int i=0; i<n; i++){
        bool lead = true;
        for(int j=i; j<n; j++){
            if(nums[j] > nums[i]){
                lead = false;
                break;
            }
        }
        if(lead == true){
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

// Optimal
vector<int> leaders2(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    int maxi = INT_MIN;

    for(int i=n-1; i>=0; i--){
        if(nums[i] > maxi){
            ans.push_back(nums[i]);
            maxi = max(maxi, nums[i]);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    vector<int> arr = {1, 2, 5, 3, 1, 2};

    vector<int> result = leaders2(arr);

    for(auto it : result){
        cout<<it<<" ";
    }

    return 0;
}