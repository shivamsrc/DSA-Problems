#include<bits/stdc++.h>
using namespace std;

// Longest common prefix --> find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".
// ["flower","flow","flight"] -> "fl"

// TC - O(n*m)
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();

    string commonPref = strs[0];

    for(int i=1; i<n; i++){
        int x = commonPref.size();
        int y = strs[i].size();
        int sml = min(x,y);
        int breakInd = 0;

        for(int j=0; j<sml; j++){                             // iterating on commonPref
            if(j == sml-1 && commonPref[j] == strs[i][j]){
                breakInd = j+1;
            }
            else if(commonPref[j] == strs[i][j]){
                // nothing
            }
            else{
                breakInd = j;
                break;
            }
        }

        commonPref = commonPref.substr(0, breakInd);
    }

    return commonPref;
}

int main(){
    // vector<string> str = {"flower", "fl", "flight"};
    vector<string> str = {"reflower","flow","flight"};

    cout<<longestCommonPrefix(str);

    return 0;
}