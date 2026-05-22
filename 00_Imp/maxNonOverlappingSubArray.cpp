#include<bits/stdc++.h>
using namespace std;

// 1546

/* Logic:

- keep adding and storing it in the set.
- sum - target = rem
- current sum = rem + target
- so if rem exists then we must have stored it in the set as we're summing every element one byv one and storing them.
- if rem exists then target exists.
- reset everything to avoid overlapping.
*/

int maxNonOverlapping(vector<int>& nums, int target) {
    int n = nums.size();
    int cnt = 0;
    unordered_set<int> st;
    st.insert(0);                          // insert 0, because let say we've {2,3} and target is 5 now the sum at i = 1 is 5 so sum - target = 0 and if it exists then cnt++;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum = sum + nums[i];

        if(st.find(sum-target) != st.end()){
            cnt++;

            st.clear();
            st.insert(0);
            sum = 0;
        }
        else{
            st.insert(sum);
        }
    }

    return cnt;
}

int main(){
    vector<int> arr = {-1,3,5,1,4,2,-9};

    cout<<maxNonOverlapping(arr, 6);

    return 0;
}