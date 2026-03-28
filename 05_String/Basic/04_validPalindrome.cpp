#include<bits/stdc++.h>
using namespace std;

// LC 125
// valid palindrome - A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

bool isAlphaNumeric(char ch){                              // we can also use inbuilt function isalnum(ch)
    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
        return true;
    }
    return false;
}

bool isPalindrome(string s) {
    int n = s.size();
    int low = 0, high = n-1;

    while(low < high){
        if(isAlphaNumeric(s[low]) == false){
            low++;
            continue;
        }
        if(isAlphaNumeric(s[high]) == false){
            high--;
            continue;
        }

        if(tolower(s[low]) == tolower(s[high])){
            low++; high--;
        }
        else{
            return false;
        }
    }

    return true;
}

int main(){
    string str = "abba";

    cout<<isPalindrome(str);

    return 0;
}