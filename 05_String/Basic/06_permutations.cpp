#include<bits/stdc++.h>
using namespace std;

// permutations in string - return true if one of s1's permutations is the substring of s2.
// check array - medium (08_arrayPermutations.cpp)

// Brute
bool getPerms(string s1, int ind, string s2){
    if(s1.size() == ind){
        if(s2.find(s1) < s2.size()){
            return true;
        }
        return false;
    }

    for(int i=ind; i<s1.size(); i++){
        swap(s1[i], s1[ind]);
        if(getPerms(s1, ind+1, s2)) return true;
        swap(s1[i], s1[ind]);
    }

    return false;
}

bool checkInclusion(string s1, string s2) {
    return getPerms(s1, 0, s2);
}

// Approach-2
// substr(start, length)
bool checkInclusion2(string s1, string s2){
    if(s2.size() < s1.size()) return false;

    sort(s1.begin(), s1.end());                                         // tc - o(mlogm)

    for(int i=0; i<=(s2.size()-s1.size()); i++){                        // tc - o(n-m+1) = o(n)
        string temp = s2.substr(i, s1.size());                          // tc - o(m) in copying m chars
        sort(temp.begin(), temp.end());                                 // tc - o(mlogm)

        if(s1 == temp) return true;                                     // tc - o(m)       in comparing 'm' chars
    }

    return false;
}

// Approach-3
bool checkInclusion3(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    if(m > n) return false;

    vector<int> s1_freq(26, 0);
    vector<int> s2_freq(26, 0);

    for(char ch : s1){
        s1_freq[ch-'a']++;
    }

    int l = 0, r = 0;                            // left & right

    // sliding window
    while(r < n){
        s2_freq[s2[r] - 'a']++;                      // add the frequency of element at right pointer.

        if(r-l+1 > m){                              // window size is (r-l+1). if window size exceeds the size of string s1 then shrink the window
            s2_freq[s2[l]-'a']--;
            l++;
        }

        if(s1_freq == s2_freq) return true;

        r++;
    }

    return false;
}

int main(){
    string s1 = "ab";
    string s2 = "widbaooo";

    cout<<checkInclusion3(s1, s2);


    return 0;
}