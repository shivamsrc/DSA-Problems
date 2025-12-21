#include<bits/stdc++.h>
using namespace std;

// majority element
// return elements that appears in the array more times than the floor value of n/3

// Brute
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int target = floor(n/3);
    vector<int> majEle;

    for(int i=0; i<n; i++){
        if(find(majEle.begin(), majEle.end(), nums[i]) != majEle.end()) continue;                               // find(start, end, number) will return the pointer to the number
        int cnt = 0;

        for(int j=0; j<n; j++){
            if(nums[i] == nums[j]) cnt++;
        }

        if(cnt > target) majEle.push_back(nums[i]);

        if(majEle.size() == 2) break;
    }

    return majEle;
}

// Better - using hashing
vector<int> majorityElement2(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    int miniTarget = floor(n/3) + 1;
    map<int,int> mp;                                   // for hashing

    for(int i=0; i<n; i++){
        mp[nums[i]]++;
        if(mp[nums[i]] == miniTarget){
            ans.push_back(nums[i]);
        }
        if(ans.size() == 2) break;
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// Optimal - modified moore's algo
vector<int> majorityElement3(vector<int>& nums){
    int n = nums.size();
    int cnt1=0, cnt2=0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for(int i=0; i<n; i++){
        if(cnt1 == 0 && ele2 != nums[i]){
            ele1 = nums[i];
            cnt1++;
        }
        else if(cnt2 == 0 && ele1 != nums[i]){
            ele2 = nums[i];
            cnt2++;
        }
        else if(ele1 == nums[i]) cnt1++;
        else if(ele2 == nums[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    // verification and return
    vector<int> ans;
    cnt1 = 0, cnt2 = 0;
    int minTarget = floor(n/3) + 1;

    for(int i=0; i<n; i++){
        if(nums[i] == ele1) cnt1++;
        if(nums[i] == ele2) cnt2++;
    }

    if(cnt1 >= minTarget) ans.push_back(ele1);
    if(cnt2 >= minTarget) ans.push_back(ele2);
    sort(ans.begin(), ans.end());                        // sorting just 2 elements
    
    return ans;
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,3,1};

    vector<int> result = majorityElement3(arr);

    for(auto it : result){
        cout<<it<<" ";
    }

    return 0;
}