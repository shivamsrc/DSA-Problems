#include<bits/stdc++.h>
using namespace std;

// Number of Sub-arrays with XOR K

// Brute
int subarraysWithXorK(vector<int> &nums, int m) {
    int n = nums.size();
    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int xorValue = 0;

            for(int k=i; k<=j; k++){
                xorValue = xorValue ^ nums[k];
            }

            if(xorValue == m) cnt++;
        }
    }

    return cnt;
}

// Better
int subarrayWithXorK2(vector<int>& nums, int m){
    int n = nums.size();
    int cnt = 0;

    for(int i=0; i<n; i++){
        int xorValue = 0;

        for(int j=i; j<n; j++){
            xorValue = xorValue ^ nums[j];

            if(xorValue == m) cnt++;
        }
    }

    return cnt;
}

// Optimal (x = xr ^ k)
int subarrayWithXorK3(vector<int>& nums, int k){
    int n = nums.size();
    map<int, int> mp;                                    // mp<frontXor, iteration>
    mp[0] = 1;                                           // initially

    int xr = 0;
    int cnt = 0;

    for(int i=0; i<n; i++){
        xr = xr ^ nums[i];                                 // find xor of 0 till i => xr

        int x = xr ^ k;                                   // finding if there is any xor 'x' from front in the subarray with total xor value is 'xr'

        cnt = cnt + mp[x];                                // if there's any xor 'x' then the no. of time or ways it's possible will be added in the count

        mp[xr]++;
    }

    return cnt;
}

int main(){
    vector<int> arr = {4, 2, 2, 6, 4};

    cout<<subarrayWithXorK3(arr, 6);

    return 0;
}