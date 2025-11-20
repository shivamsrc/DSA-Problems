#include<bits/stdc++.h>
using namespace std;

// Union of Two Sorted Array

// Brute force
vector<int> unionArr(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    set<int> st;

    for(int i=0; i<n1; i++){
        st.emplace(nums1[i]);
    }

    for(int i=0; i<n2; i++){
        st.emplace(nums2[i]);
    }

    vector<int> unionArray;
    for(auto it : st){
        unionArray.emplace_back(it);
    }

    return unionArray;
}

// Optimal - Two pointer approach
vector<int> unionArray(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;

    while(i<n1 && j<n2){
        if(nums1[i] <= nums2[j]){
            if(unionArr.size() == 0 || unionArr.back() != nums1[i]){        // if no element then put it or if no repetation then put it.
                unionArr.emplace_back(nums1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != nums2[j]){
                unionArr.emplace_back(nums2[j]);
            }
            j++;
        }
    }

    while(i<n1){
        if(unionArr.size() == 0 || unionArr.back() != nums1[i]){
            unionArr.emplace_back(nums1[i]);
        }
        i++;
    }

    while(j<n2){
        if(unionArr.size() == 0 || unionArr.back() != nums2[j]){
            unionArr.emplace_back(nums2[j]);
        }
        j++;
    }

    return unionArr;
}

int main(){
    vector<int> arr1 = {1,1,2,3,4,5};
    vector<int> arr2 = {2,3,4,4,5,6};

    vector<int> un = unionArray(arr1, arr2);

    for(auto it : un){
        cout<<it<<" ";
    }

    return 0;
}