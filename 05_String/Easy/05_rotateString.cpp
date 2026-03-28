#include<bits/stdc++.h>
using namespace std;

// Rotate String (LC 796) --> Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s. A shift on s consists of moving the leftmost character of s to the rightmost position.
// rotate(begin, begin+k, end) → left rotate by k
// rotate(begin, end-k, end) → right rotate by k


// Brute
bool rotateString(string s, string goal) {
    int n = s.size();

    if(s == goal) return true;

    for(int i=0; i<n; i++){
        char temp = s[0];
        for(int j=0; j<n-1; j++){
            s[j] = s[j+1];
        }
        s[n-1] = temp;
        if(s == goal) return true;
    }

    return false;
}


// Optimal
bool rotateString2(string s, string goal){
    int n = s.size();
    int m = goal.size();

    if(n != m) return false;

    string concatStr = s + s;

    if(concatStr.find(goal) < concatStr.size()) return true;
    return false;
}

int main(){
    string s = "abcde", goal = "cdeab";

    cout<<rotateString2(s, goal);

    return 0;
}