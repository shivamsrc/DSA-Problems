#include<bits/stdc++.h>
using namespace std;

// Longest happy prefix (LC 1392) --> return the longets prefix which is also a suffix
// ex: ababab --> abab
// just use LPS (longest prefix suffix) table of KMP

string longestPrefix(string s) {
    int n = s.size();
    
    vector<int> LPS(n);

    LPS[0] = 0;
    int i = 1;
    int len = 0;

    while(i < n){
        if(s[i] == s[len]){
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

    return s.substr(0, LPS[n-1]);
}

int main(){
    string str = "level";

    cout<<longestPrefix(str);

    return 0;
}