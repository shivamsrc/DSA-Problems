#include<bits/stdc++.h>
using namespace std;

// 3 Sum: return all the unique triplets whose sum is 0.

// Brute
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(nums[i]+nums[j]+nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Better
vector<vector<int>> threeSum2(vector<int>& nums){
    int n = nums.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        set<int> hashSet;
        for(int j=i+1; j<n; j++){
            int third = - (nums[i] + nums[j]);               // nums[i] + nums[j] + third = 0

            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashSet.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

// Optimal 
vector<vector<int>> threeSum3(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];

            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j<k && nums[j] == nums[j-1]) j++;                     // to make sure that while moving j or k, if we get to the same value as previous one then we keep on moving. (we also make sure that if j & k have crossed then we need to stop)
                while(j<k && nums[k] == nums[k+1]) k--;
            }
        }

    }

    return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};

    vector<vector<int>> result = threeSum3(arr);

    for(auto it : result){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }


    return 0;
}