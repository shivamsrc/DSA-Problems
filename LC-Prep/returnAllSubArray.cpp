#include<bits/stdc++.h>
using namespace std;

// return all the sub arrays [optimal = o(n^3)]
vector<vector<int>> allSubArray(vector<int> nums){
    vector<vector<int>> ans;
    int n = nums.size();

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            vector<int> temp;
            for(int k=i; k<=j; k++){
                temp.push_back(nums[k]);
            }
            ans.push_back(temp);
        }
    }

    return ans;
}

// Even though we're using 2 loops here the tc is still same. Because, ans.push_back(temp) copies the entire temp vector in every iteration. Since the size of temp keeps growing (1, 2, 3, ... , n), the total copying cost behaves like O(n²) for each starting index, making the total complexity O(n³).
vector<vector<int>> allSubArray2(vector<int> nums){
    vector<vector<int>> ans;
    int n = nums.size();

    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=i; j<n; j++){
            temp.push_back(nums[j]);
            ans.push_back(temp);
        }
    }

    return ans;
}


int main(){
    vector<int> arr = {1,2,3,4,5};

    vector<vector<int>> ans = allSubArray(arr);

    for(auto it : ans){
        for(auto n : it){
            cout<<n<<" ";
        }
        cout<<endl;
    }

}