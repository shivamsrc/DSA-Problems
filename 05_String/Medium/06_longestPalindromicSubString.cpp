#include<bits/stdc++.h>
using namespace std;

// Longest Palindromic SubString --> Given a string s, return the longest palindromic substring in s. A string is palindromic if it reads the same forward and backward.

// Brute
bool palindromeCheck(string s){
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s==s2;
}

string longestPalindrome(string s) {
    int n = s.size();

    string longest = string(1, s[0]);
    int maxi = 1;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            string subs = s.substr(i, j-i+1);
            if(palindromeCheck(subs)){
                int len = subs.size();
                if(len > maxi){
                    longest = subs;
                    maxi = len;
                }
            }
        }
    }

    return longest;
}

// Optimal
// expand from center. for each char do two expansion odd and even.
string longestPalindrome2(string s){
    int n = s.size();

    int start = 0, maxLen = 0;                       // to create the longest palindromic substr(start, Len)

    for(int i=0; i<n; i++){

        // odd
        int l = i, r = i;
        while(l >= 0 && r < n && s[l]==s[r]){
            if(r-l+1 > maxLen){
                start = l;
                maxLen = r-l+1;
            }
            l--;
            r++;
        }

        // even
        l = i, r = i+1;
        while(l >= 0 && r < n && s[l]==s[r]){
            if(r-l+1 > maxLen){
                start = l;
                maxLen = r-l+1;
            }
            l--;
            r++;
        }
    }

    return s.substr(start, maxLen);
}

int main(){
    string str = "cbbd";

    cout<<longestPalindrome2(str);

    return 0;
}