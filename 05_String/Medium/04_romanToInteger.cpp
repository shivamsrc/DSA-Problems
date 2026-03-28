#include<bits/stdc++.h>
using namespace std;

// Roman to Integer (LC 13)
// "MCMXCIV" --> 1994

//
int romanToInt(string s) {
    unordered_map<string, int> mp = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
    int n = s.size();
    int ans = 0;

    for(int i=0; i<n; i++){
        char ch = s[i];
        if(i == n-1){
            ans += mp[string(1, ch)];
            break;
        }
        char nextCh = s[i+1];


        if(mp[string(1, ch)] >= mp[string(1, nextCh)]){
            ans += mp[string(1, ch)];
        }
        else{
            string str = string(1, ch) + string(1, nextCh);
            ans += mp[str];
            i++;
        }
    }

    return ans;
}

int main(){
    string str = "MCMXCIV";

    cout<<romanToInt(str);

    return 0;
}