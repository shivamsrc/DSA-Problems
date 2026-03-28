#include<bits/stdc++.h>
using namespace std;

// String Compression (LC 443) --> Given an array of characters chars, For each group of consecutive repeating characters in chars, compress it like "(char1)(char1 count)(char2)(char2 count)..." if the count of any char is 1 then don't write its count in the compressed string. return the lenght of this compressed string.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars.

// Optimal
int compress(vector<char>& chars) {
    int n = chars.size();
    
    int l = 0, r = 0;
    int count = 1;

    while(r < n){
        if(r == n-1 || chars[r+1] != chars[r]){
            chars[l++] = chars[r++];

            if(count != 1){
                string s = to_string(count);
                for(char c : s){
                    chars[l++] = c;
                }
            }

            count = 1;
        }
        else{
            r++;
            count++;
        }
    }

    chars.resize(l);

    return chars.size();
}

int main(){
    vector<char> ch = {'a', 'a', 'a', 'b', 'b' };

    cout<<compress(ch);

    return 0;
}