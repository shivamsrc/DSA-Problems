#include<bits/stdc++.h>
using namespace std;

// Palindromic Substrings (LC 647) --> Given a string s, return the no. of palindromic substrings in it.

// Brute
int countSubstrings2(string s) {
    int n = s.size();
    int cnt = 0;

    for(int i=0; i<n; i++){
        if(i==n-1){
            cnt++;
            break;
        }

        cnt++;

        for(int j=i+1; j<n; j++){
            string substr = s.substr(i, j-i+1);
            string temp = substr;
            reverse(temp.begin(), temp.end());

            if(substr == temp){
                cnt++;
            }
        }
    }

    return cnt;
}

// Optimal
// Expand from center.
int countSubstrings(string s){
    int n = s.size();

    int cnt = 0;

    for(int i=0; i<n; i++){

        // odd
        int l=i, r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }

        // even
        l=i; r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }
    }

    return cnt;
}

int main(){
    string s = "aaa";

    cout<<countSubstrings(s);

    return 0;
}