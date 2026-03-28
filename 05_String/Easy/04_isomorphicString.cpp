#include<bits/stdc++.h>
using namespace std;

// Isomorphic string (LC 205) --> Given two strings s and t, determine if they are isomorphic.
// if string 's' can be made identical to string 't' by mapping characters in 's' to 't'
// egg = add (e->a, g->d)

// Brute
bool isIsomorphic(string s, string t) {
    int n = s.size();                             // both string has same size

    // to make sure one unique char maps to any one unique char only. 
    // with one map we can only ensure that keys are unique but to make sure values are also unique for the key we need to check reverse as well.
    map<char, char> mp;
    map<char, char> mp2;

    for(int i=0; i<n; i++){
        mp.emplace(s[i], t[i]);
        mp2.emplace(t[i], s[i]);
    }

    string s1 = s, t1 = t;

    for(int i=0; i<n; i++){
        s[i] = mp[s[i]];
        t1[i] = mp2[t[i]];
    }


    return (s==t && s1==t1) ? true : false;
}

int main(){
    string s = "badc", t = "baba";

    cout<<isIsomorphic(s, t);

    return 0;
}