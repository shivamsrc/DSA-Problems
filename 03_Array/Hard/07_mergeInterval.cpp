#include<bits/stdc++.h>
using namespace std;

// merge overlapping sub-intervals

// Brute
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());

    for(int i=0; i<n; i++){
        vector<int> mergedInt = intervals[i];                              // considering the currect sub-interval as a new mergedInterval

        if(!ans.empty() && ans.back()[1] >= mergedInt[1]) continue;       // means if already included or part of any merged interval then move to the next interval for starting a new mergedInterval

        for(int j=i+1; j<n; j++){
            if(intervals[j][0] <= mergedInt[1]){
                mergedInt[1] = max(intervals[j][1], mergedInt[1]);
            }
            else{
                break;
            }
        }

        ans.push_back(mergedInt);
    }

    return ans;
}

// Optimal
vector<vector<int>> merge2(vector<vector<int>>& intervals){
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> mergedInt = intervals[0];

    for(int i=1; i<n; i++){

        if(intervals[i][0] <= mergedInt[1]){
            mergedInt[1] = max(intervals[i][1], mergedInt[1]);
        }
        else{
            ans.push_back(mergedInt);
            mergedInt = intervals[i];
        }
    }

    ans.push_back(mergedInt);                                               // to add the last merged interval

    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,4}, {2,3}};

    vector<vector<int>> result = merge2(arr);

    for(auto it : result){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}