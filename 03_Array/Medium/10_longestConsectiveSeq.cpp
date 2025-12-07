#include<bits/stdc++.h>
using namespace std;

// Longest consequtive sequence

// Brute
bool ls(vector<int>& arr, int n){
    bool found = false;
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i] == n){
            found = true;
            break;
        }
    }

    return found;
}

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    int longest = 1;

    for(int i=0; i<n; i++){
        int x = nums[i];
        int cnt = 1;
        while(ls(nums, x) == true){
            x = x+1;                                           // if the current element is found in the linear search then look for the next one
            cnt = cnt + 1;
        }

        longest = max(longest, cnt);
    }

    return longest;
}


// Better
int longestConsecutive2(vector<int>& nums){
    int n = nums.size();
    int lastElement = INT_MIN;
    int longest = 1;
    int cnt = 1;

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if(nums[i] == lastElement){
            continue;
        }
        else if(nums[i] == lastElement+1){
            lastElement = nums[i];
            cnt++;
            longest = max(longest, cnt);
        }
        else if(nums[i] != lastElement+1){
            lastElement = nums[i];
            cnt = 1;
        }
    }

    return longest;
}


// Optimal
// for every element, check if the previous element exists, if it exists then move and if it doesn't means it's a starting point and check for the next consecutive elements
int longestConsecutive3(vector<int>& nums){
    int n = nums.size();
    if(n==0) return 0;
    unordered_set<int> st;
    int longest = 1;

    for(int i=0; i<n; i++){                // inserting elements in the set
        st.insert(nums[i]);
    }

    for(auto it : st){
        if(st.find(it-1) == st.end()){                          // if the previous consecutive element is not found then it will point to the st.end() means it's the starting element of a sequence
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){                   // means if next element is found 
                cnt = cnt + 1;
                x = x + 1;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}

int main(){
    vector<int> arr = {102, 100, 3, 1, 1, 101, 4, 103, 104, 2, 5, 6};

    cout<<longestConsecutive3(arr);

    return 0;
}