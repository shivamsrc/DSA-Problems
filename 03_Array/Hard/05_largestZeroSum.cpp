#include<bits/stdc++.h>
using namespace std;

// Largest sub-array with zero sum

// Brute
int maxLen(vector<int>& nums) {
    int n = nums.size();
    int len = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += nums[k];
            }
            if(sum == 0){
                len = max(len, j-i+1);
            }
        }
    }

    return len;
}

// Better
int maxLen2(vector<int>& nums){
    int n = nums.size();
    int len = 0;

    for(int i=0; i<n; i++){
        int sum = 0;

        for(int j=i; j<n; j++){
            sum += nums[j];

            if(sum == 0){
                len = max(len, j-i+1);
            }
        }
    }

    return len;
}

// Optimal
int maxLen3(vector<int>& nums){
    int n = nums.size();
    int len = 0, sum = 0;
    map<int, int> mp;                                          // here mp<sum, index>

    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == 0){
            len = max(len, i+1);
        }

        if(mp.find(sum) != mp.end()){
            len = max(len, i-mp[sum]);
        }
        else mp[sum] = i;
    }

    return len;
}

int main(){
    vector<int> arr = {1, -1, 3, 2, -2};

    cout<<maxLen3(arr);

    return 0;
}