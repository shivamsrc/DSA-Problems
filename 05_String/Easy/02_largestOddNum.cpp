#include<bits/stdc++.h>
using namespace std;

// Largest odd number in string (LC 1903) --> You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// Brute
// find all the substring and check
string largestOddNumber(string num) {
    int n = num.size();
    string s = "";
    int maxi = -1;

    for(int i=0; i<n; i++){
        int j = i;
        while(j < n){
            s = s + num[j];
            int temp = stoi(s);
            if(temp % 2 != 0){
                maxi = max(maxi, temp);
            }
            j++;
        }

        s = "";
    }

    return maxi==-1? "" : to_string(maxi);
}

// Optimal
// find the last odd digit with index
string largestOddNumber2(string num){
    int n = num.size();
    int lastOddIndex = -1;

    for(int i=0; i<n; i++){
        int digit = num[i] - '0';                  // when you do arithmetic on char, they are automatically converted to int (ASCII values)

        if(digit % 2 != 0){
            lastOddIndex = i;
        }
    }

    string ans = num.substr(0, lastOddIndex+1);

    return lastOddIndex==-1 ? "" : ans;
}


int main(){
    string str = "52";

    cout<<largestOddNumber2(str);

    return 0;
}