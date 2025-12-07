#include<bits/stdc++.h>
using namespace std;

// Majoity Element
// return the element that appears more than n/2 time.

// Brute
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int target = floor(n/2);

    for(int i=0; i<n; i++){
        int cnt=0;

        for(int j=0; j<n; j++){
            if(nums[j]==nums[i]) cnt++;
        }

        if(cnt > target) return nums[i];
    }

    return -1;
}

// Better - using hashMap
int majorityElement2(vector<int>& nums){
    int n = nums.size();
    int target = floor(n/2);
    map<int, int> mp;                                            // map<index, value> = map<element, occurance>

    for(int i=0; i<n; i++){
        mp[nums[i]]++;                                       // at the index (element) increase the value (occurance)
    }

    for(auto it : mp){
        if(it.second > target) return it.first;
    }

    return -1;
}

// Optimal - moore's voting algorith
int majorityElement3(vector<int>& nums){
    int n = nums.size();
    int target = floor(n/2);
    int el;
    int cnt=0;

    for(int i=0; i<n; i++){
        if(cnt==0){
            cnt++;
            el = nums[i];
        }
        else if(el == nums[i]) cnt++;

        else cnt--;
    }

    // verifying - only if it is given that majority element can or can't exist
    int cnt1=0;
    for(int i=0; i<n; i++){
        if(el == nums[i]) cnt1++;
    }
    if(cnt1 > target) return el;

    return -1;
}

int main(){
    vector<int> arr = {7,3,7};

    cout<<majorityElement3(arr);

    return 0;
}