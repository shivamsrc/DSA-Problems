#include<bits/stdc++.h>
using namespace std;

// string to integer (LC 8) using recursion (already solved this before without recursion)

// ignore leading white spaces
// include any leading '+' or '-' sign
// if any non-digit char is encountered then stop immediately. (if whitespaces are encounter in mid then also stop).
// if ans > INT_MAX then return INT_MAX or INT_MIN if less.

void ansInt(string &s, int i, int &ans, int &sign){
    if(i == s.size()) return;

    // if any non digit char is encountered in mid then return 
    if(i != 0 && !(isdigit(s[i])) && (isdigit(s[i-1]) || s[i-1] == '-' || s[i-1] == '+')) return;

    if(s[i] == ' '){
        ansInt(s, i+1, ans, sign);
    }

    if(s[i] == '-' || s[i] == '+'){
        sign = s[i] == '-' ? -1 : 1;
        ansInt(s, i+1, ans, sign);
    }

    if(isdigit(s[i])){
        int digit = s[i] - '0';
        if(ans > INT_MAX/10 || (ans == INT_MAX / 10 && digit > 7)){
            ans = sign == -1 ? INT_MIN : INT_MAX;
            return;
        }
        ans = ans*10 + digit;
        ansInt(s, i+1, ans, sign);
    }
}

int myAtoi(string s){

    int ans = 0;
    int sign = 1;

    ansInt(s, 0, ans, sign);

    if(ans == INT_MIN) return ans;
    return (int)sign*ans;
}

int main(){
    cout<<myAtoi("-2147483647");

    return 0;
}