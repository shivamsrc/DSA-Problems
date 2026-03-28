#include<bits/stdc++.h>
using namespace std;

// Valid Anagram (LC 242) --> If s2 is an anagram of s1, then by rearranging the characters of s2 (using each character exactly once), we can obtain s1.
// Anagrams must use exactly the same characters with the same frequency.


// Better
bool isAnagram(string s, string t) {
    int n = s.size();
    int m = t.size();

    if(n != m) return false;

    map<char, int> mp1;
    map<char, int> mp2;

    for(int i=0; i<n; i++){
        mp1[s[i]]++;
        mp2[t[i]]++;
    }

    return mp1 == mp2 ? true : false;
}

// Optimal
bool isAnagram2(string s, string t){
    int n = s.size();
    int m = t.size();

    if(n != m) return false;

    vector<int> freq(26, 0);

    for(int i=0; i<n; i++){
        freq[s[i] - 'a']++;                                    // 'a'-'a' = 0 index, 'b'-'a' = 1 index....
        freq[t[i] - 'a']--;
    }

    return freq == vector<int> (26, 0) ? true : false;

}

int main(){
    string s = "a", t = "ab";

    cout<<isAnagram2(s, t);

    return 0;
}