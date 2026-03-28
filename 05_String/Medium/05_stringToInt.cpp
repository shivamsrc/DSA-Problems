#include<bits/stdc++.h>
using namespace std;

// string to integer
// ignore leading white spaces
// include any leading '+' or '-' sign
// if any non-digit char is encountered then stop immediately. (if whitespaces are encounter in mid then also stop).
// if ans > INT_MAX then return INT_MAX or INT_MIN if less.

int myAtoi(string s){
    int n = s.size();

    if(n==0) return 0;

    int i=0;

    while(s[i] == ' '){
        i++;
    }
    if(i==n) return 0;
    s = s.substr(i);                        // i to last of string, if lenght not given of substring

    int sign = 1;
    if(s[0]=='-') sign = -1;

    long ans = 0;
    i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

    while(i < s.size()){
        if(s[i]==' ' || !isdigit(s[i])) break;                         // if any space is found in mid or if a non-digit is found then break.

        int digit = s[i] - '0';

        // INT_MAX = 2147483647
        // INT_MAX / 10 = 214748364
        // if ans > INT_MAX / 10 => ans = 214748365 then on multiplying by 10 we'll definately get ans > INT_MAX
        // but if ans = INT_MAX / 10 => ans = 214748364 then on multiplying we'll get 2147483640 and we can add 0-7 only then only it will remian in the range otherwise if we add say 8 or 9 then we'll get 2147483648 > INT_MAX 
        if((ans > INT_MAX / 10) || (ans == INT_MAX / 10 && digit > 7)){
            return sign==1 ? INT_MAX : INT_MIN;
        }

        ans = ans * 10 + (s[i]-'0');

        i++;
    }

    return (int)sign*ans;
}

int main(){
    string str = "21474836460";

    cout<<myAtoi(str);

    return 0;
}