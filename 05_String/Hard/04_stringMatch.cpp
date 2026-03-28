#include<bits/stdc++.h>
using namespace std;

// Find the Index of the First Occurrence in a String (LC 28)

// Brute 
int strStr2(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    for(int i=0; i<n; i++){
        int x = i, y=0;
        int m2 = m;
        while(m2 > 0 && i+m < n){
            if(haystack[x] == needle[y]){
                x++;
                y++;
                m2--;
            }
            else{
                break;
            }
        }
        if(m2 == 0) return i;
    }

    return -1;
}

// OPTIMAL - USING KMP AND LPS

void computeLPS(vector<int> &LPS, string needle, int m){
    int len = 0;

    LPS[0] = 0;

    int i = 1;

    while(i < m){
        if(needle[i] == needle[len]){
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

int strStr(string haystack, string needle){
    int n = haystack.size();
    int m = needle.size();

    vector<int> LPS(m, 0);
    computeLPS(LPS, needle, m);

    // apply KMP
    int ans = -1;
    int i=0, j=0;

    while(i < n){
        if(haystack[i] == needle[j]){
            i++;
            j++;
        }

        if(j == m){
            return i-m;
        }
        else if(i<n && haystack[i] != needle[j]){
            if(j != 0){
                j = LPS[j-1];
            }
            else{
                i++;
            }
        }
    }

    return -1;
}

int main(){
    string haystack = "saadbutsada", needle = "sad";

    cout<<strStr(haystack, needle);

    return 0;
}