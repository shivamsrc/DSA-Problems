#include<bits/stdc++.h>
using namespace std;

// LC 1910
// Remove all occurances of a substring
string removeOccurrences(string s, string part) {
    string str = s;
    int n = s.size();
    int m = part.size();

    while(str.size() != 0 && str.find(part) < str.size()){
        int ptr = str.find(part);                               // find - finds the substring and if it exists then it returns the first index of the substring in the string and return it otherwise it'll return some value that will be greater than the size of the substring.
        if(ptr < str.size()){
            str.erase(ptr, m);                                 // erase(position, len) - it erases in the string from index "ptr" and to the length "m" i.e, from ptr to ptr+m.
        }
    }

    return str;
}

// find function implementation:
int findSubstring(string s, string part) {
    int n = s.size();
    int m = part.size();

    for(int i = 0; i <= n - m; i++) {
        int j;

        for(j = 0; j < m; j++) {                                         // if substring is there then it'll run 'm' times and j = m.
            if(s[i + j] != part[j]) {
                break;
            }
        }

        if(j == m) {
            return i;   // substring found
        }
    }

    return -1;  // equivalent to string::npos
}

// erase function implementation:
string eraseSubstring(string s, int pos, int len) {
    int n = s.size();

    for(int i = pos + len; i < n; i++) {
        s[i - len] = s[i];
    }

    s.resize(n - len);                                   // programmingpy (remove gram) -> left shift => promingpyming -> resize => promingpy

    return s;
}

int main(){
    string str = "daabcbaabcbc";
    
    cout<<removeOccurrences(str, "abc");

    return 0;
}