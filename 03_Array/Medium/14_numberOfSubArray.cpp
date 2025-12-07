#include<bits/stdc++.h>
using namespace std;

// Number of sub arrays with sum K

// Brute
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0;

    for(int i=0; i<n; i++){

        for(int j=i; j<n; j++){

            int sum=0;
            for(int x=i; x<=j; x++){
                sum = sum + nums[x];
            }
            if(sum == k) cnt++;
        }
    }

    return cnt;
}

// Better
int subarraySum2(vector<int>& nums, int k){
    int n = nums.size();
    int cnt=0;

    for(int i=0; i<n; i++){
        int sum=0;
        
        for(int j=i; j<n; j++){
            sum = sum + nums[j];

            if(sum == k) cnt++;
        }
    }

    return cnt;
}

// Optimal
int subarraySum3(vector<int>& nums, int k){
    int n = nums.size();
    map<int, int> mp;                             // mp = <prefSum, noOftime>
    mp[0] = 1;
    int cnt=0;
    int prefSum = 0;                            // total sum of the previous elements

    for(int i=0; i<n; i++){
        prefSum = prefSum + nums[i];
        int remove = prefSum - k;              // if this value 'remove' is removed from the total sum then we get the required value

        cnt += mp[remove];                     // the number of times the remove value exists, the no. of count as we can remove it that many time to get the required value.

        mp[prefSum] += 1;                      // increase the number of prefSum and add it if doesn't exists previously
    }

    return cnt;
}

int main(){
    vector<int> arr = {1,1,1,2};

    cout<<subarraySum3(arr, 2);

    return 0;
}