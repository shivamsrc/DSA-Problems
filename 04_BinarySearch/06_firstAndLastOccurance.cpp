#include<bits/stdc++.h>
using namespace std;

// first and last occurance of any number 'x'

// Brute - Linear search

// Optimal - Binary search
int lb(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid]>=target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

int ub(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid]>target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans;

    int first = lb(nums, target);                  // it'll give the first occurance
    int last = ub(nums, target) - 1;               // it'll give the last occurance
    
    if(first < n && nums[first]==target && nums[last]==target){
        ans.push_back(first);
        ans.push_back(last);
    }
    else{
        ans.push_back(-1);
        ans.push_back(-1);
    }

    return ans;
}


// Optimal - Binary search (without lowerBound and upperBound)
int firstOccurance(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int first = -1;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            first = mid;
            high = mid-1;
        }
        else if(nums[mid]<target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return first;
}

int lastOccurance(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0, high = n-1;
    int last = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid]==target){
            last = mid;
            low = mid + 1;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return last;
}

vector<int> searchRange2(vector<int>& nums, int target){
    int n = nums.size();

    int first = firstOccurance(nums, target);
    if(first == -1) return {-1,-1};
    int last = lastOccurance(nums, target);
    return {first,last};
}

int main(){
    vector<int> arr = {5,7,7,8,8,10};

    vector<int> result = searchRange2(arr, 7);

    for(auto it: result){
        cout<<it<<endl;
    }

    return 0;
}