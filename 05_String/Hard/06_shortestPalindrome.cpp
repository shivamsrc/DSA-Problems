#include<bits/stdc++.h>
using namespace std;

// Shortest Palindrome (LC 214)


// Approach-1
string shortestPalindrome(string s){
    string rev = s;
    reverse(rev.begin(), rev.end());

    for(int i=0; i<s.size(); i++){
        if(s.substr(0, s.size()-i) == rev.substr(i)){                // substr(i) --> i to end index
            return rev.substr(0, i) + s;
        }
    }

    return rev + s;
}

// Approach-1 (fix)
// memory limit exceeded because When you do substr, this creates a new string in the memory. If you do this in a loop 1000 times → 1000 new strings created in RAM → Memory Limit Exceeded. When you do memcmp, it just gives a **pointer** to the existing memory and reads existing memory directly. No new string created. on matching, memcmp returns 0;
string shortestPalindrome2(string s){
    int n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());

    for(int i=0; i<n; i++){
        if(memcmp(s.c_str(), rev.c_str()+i, n-i) == 0){                  // memcmp(pointer to first memory block, pointer to second memory block, no. of bytes to compare)
            return rev.substr(0, i) + s;
        }
    }

    return rev + s;
}


// Using KMP
void computeLPS(vector<int> &LPS, string comb){
    int N = comb.size();

    LPS[0] = 0;
    int i = 1;
    int len = 0;

    while(i < N){
        if(comb[i] == comb[len]){
            len++;
            LPS[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = LPS[len-1];
            }
            else{
                LPS[i] = 0;
                i++;
            }
        }
    }
}

string shortestPalindrome3(string s){
    int n = s.size();

    string rev = s;
    reverse(rev.begin(), rev.end());

    string comb = s + "-" + rev;
    vector<int> LPS(comb.size());
    computeLPS(LPS, comb);

    int longestLPSLength = LPS[comb.size()-1];

    return rev.substr(0, n-longestLPSLength) + s;
}

int main(){
    string s = "aabba";

    cout<<shortestPalindrome3(s);

    return 0;
}