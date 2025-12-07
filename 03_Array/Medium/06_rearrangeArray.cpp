#include<bits/stdc++.h>
using namespace std;

// Rearrange the array in alternating positive and negative items (positive one should be at the first place always)

// Brute
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        if(nums[i]>0) pos.push_back(nums[i]);
        else if(nums[i]<0) neg.push_back(nums[i]);
    }

    for(int i=0; i<(n/2); i++){
        ans[i*2] = pos[i];                        // as the positive will always take the even indexes and negative one will always take the odd indexes
        ans[i*2+1] = neg[i];
    }

    return ans;
}

// Optimal
vector<int> rearrangeArray2(vector<int>& nums){
    int n = nums.size();
    int posIndex = 0;
    int negIndex = 1;
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        if(nums[i] > 0){
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
        else{
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    return ans;
}


// 2nd Varity - if positive and negative numbers are not same
vector<int> rearrangeArray3(vector<int>& nums){
    int n = nums.size();
    vector<int> pos, neg;
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        if(nums[i]>0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }

    if(pos.size()>neg.size()){
        for(int i=0; i<neg.size(); i++){
            ans[i*2] = pos[i];
            ans[i*2+1] = neg[i];
        }

        int index = neg.size() * 2;
        for(int i=neg.size(); i<pos.size(); i++){
            ans[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            ans[i*2] = pos[i];
            ans[i*2+1] = neg[i];
        }

        int index = pos.size() * 2;
        for(int i=pos.size(); i<neg.size(); i++){
            ans[index] = neg[i];
            index++;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4, 5, 11, 2};

    vector<int> result = rearrangeArray3(arr);

    for(auto it: result){
        cout<<it<<" ";
    }

    return 0;
}