#include<bits/stdc++.h>
using namespace std;

// KMP Algorithm
// 1-based indexing

void computeLPS(vector<int> &LPS, string pat, int m){
    int len = 0;                     // length of previous longest prefix and suffix which were equal

    LPS[0] = 0;

    int i = 1;

    while(i < m){
        if(pat[i] == pat[len]){
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

vector<int> KMP(string txt, string pat){
    int n = txt.size();
    int m = pat.size();

    vector<int> result;

    vector<int> LPS(m, 0);
    computeLPS(LPS, pat, m);

    // apply kmp
    int i=0, j=0;
    while(i < n){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }

        if(j == m){
            result.push_back(i-m+1);                 // for 1 based indexing
            j = LPS[j-1];                            // reset j to look for next match
        }
        else if(i<n && txt[i] != pat[j]){
            if(j != 0){
                j = LPS[j-1];
            }
            else {                                    // if j=0 then we can't move j further back so in that case move i forward.
                i++;
            }
        }
    }

    return result;
}

int main(){
    string text = "geekohgeek", pattern = "geek";

    vector<int> ans = KMP(text, pattern);

    for(auto it : ans){
        cout<<it<<" ";
    }

    return 0;
}