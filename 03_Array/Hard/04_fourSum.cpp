#include<bits/stdc++.h>
using namespace std;

// 4 Sum : return all the quadruplets whose sum is equal to the given target

// Brute
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Better - using hashing
vector<vector<int>> fourSum2(vector<int>& nums, int target){
    int n = nums.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<long long> hashSet;
            for(int k=j+1; k<n; k++){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;

                if(hashSet.find(fourth) != hashSet.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], int(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Optimal - similar to the 3sum
vector<vector<int>> fourSum3(vector<int>& nums, int target){
    int n = nums.size();
    set<vector<int>> st;
    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;

        for(int j=i+1; j<n; j++){
            if(j != i+1 && nums[j] == nums[j-1]) continue;                    // j != i+1 means if 'j' is not at the starting position as it's starting form the i+1
            int k = j+1;
            int l = n-1;
            
            while(k<l){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];

                if(sum == target){
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    st.insert(temp);
                    k++; l--;
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
                else if(sum < target) k++;
                else l--;
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main(){
    vector<int> arr = {1,0,-1,0,-2,2};

    vector<vector<int>> result = fourSum3(arr, 0);

    for(auto it : result){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}