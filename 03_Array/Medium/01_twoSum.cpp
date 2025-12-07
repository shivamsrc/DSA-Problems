#include<bits/stdc++.h>
using namespace std;

// two sum

// Brute
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;

            else if(nums[i] + nums[j] == target) return {i,j};
        }
    }

    return {};
}

// Better - using hashing: store one element in the hashmap and check whether the other part is available there in the hashmap or not. if i'm at 2 and my target is 14 then i'll look for 12 in the hash map
vector<int> twoSum2(vector<int> nums, int target){
    int n = nums.size();
    map<int, int> mp;

    for(int i=0; i<n; i++){
        if(mp.find(target-nums[i]) != mp.end()){                          // if mp.find() doesn't find the given element then it will points to the mp.end(). so it means if the element is found then only this condition block will be executed.
            return {mp[target-nums[i]], i};
        }
        mp[nums[i]] = i;                                          // if element not found then store that element in the map 
    }

    return {};
}

// Optimal - using two pointers approach (optimal for variety1 type problem as we just have to tell yes and no and changing the indexes during the sorting is not a problem)
vector<int> twoSum3(vector<int>& nums, int target){
    int n = nums.size();
    int left = 0;
    int right = n-1;

    sort(nums.begin(), nums.end());

    while(left<n-1 && right > 0){
        if(nums[left]+nums[right]<target){
            left++;
        }
        else if(nums[left]+nums[right]>target){
            right--;
        }
        return {left, right};
    }

    return {};
}

int main(){
    vector<int> arr = {2,7,11,15,1};

    vector<int> result = twoSum3(arr, 12);

    cout<<result[0]<<" "<<result[1];

    return 0;
}