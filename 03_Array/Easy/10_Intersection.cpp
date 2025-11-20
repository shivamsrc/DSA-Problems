#include<bits/stdc++.h>
using namespace std;
// Intersection of two sorted arrays

//Brute force
vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> intArr;
    vector<int> vis(n2);                           // will keep track whether an element is already taken or not. Intially all the elements are valued 0.

    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(vis[j] == 0 && nums1[i] == nums2[j]){
                intArr.emplace_back(nums1[i]);
                vis[j] = 1;
                break;
            }
            else if(nums2[j] > nums1[i]) break;              // if the element of nums1 that we are searching is smaller than the current element of nums2 then we'll break because we can't find it forward as it's sorted.
        }
    }

    return intArr;
}

// Optimal Solution
// two pointer approach
vector<int> intersection2(vector<int> nums1, vector<int> nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i=0;
    int j=0;
    vector<int> ans;

    while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){                            // if nums1[i] is smaller than nums2[j] than nums1[i] doesn't have any match so move to a higher value while keeping the j pointer at same value to match again.
            i++;
        }
        else if(nums1[i]>nums2[j]){
            j++;
        }
        else{
            ans.emplace_back(nums1[i]);
            i++;
            j++;
        }
    }

    return ans;
}

int main(){
    vector<int> arr1 = {1,1,2,3,4,4,5};
    vector<int> arr2 = {2,3,4,4,5,6};

    vector<int> un = intersection2(arr1, arr2);

    for(auto it : un){
        cout<<it<<" ";
    }

    return 0;
}