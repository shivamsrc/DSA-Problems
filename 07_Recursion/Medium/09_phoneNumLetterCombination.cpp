#include<bits/stdc++.h>
using namespace std;

// Letter Combinations of a Phone Number (LC 17) --> It's same as how we used to type letter in keypad phone where we had to click a number to get a corresponding character. so let say if we've "23" so we can get one char from 2="abc" and one from 3="def" i.e, "ad", "ae" etc.
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

void combination(vector<string> &ans, string &digits, string &comb, int dIdx){         // dIdx points digit index
    if(dIdx == digits.size()){
        ans.push_back(comb);
        return;
    }

    char d = digits[dIdx];
    string str = mp[d];

    for(int i=0; i<str.size(); i++){
        comb.push_back(str[i]);
        combination(ans, digits, comb, dIdx+1);
        comb.pop_back();
    }

}

vector<string> letterCombinations(string digits) {

    vector<string> ans;
    string comb = "";

    combination(ans, digits, comb, 0);

    return ans;
}

int main(){
    string digits = "23";

    vector<string> ans = letterCombinations(digits);

    for(auto it : ans){
        cout<<it;
        cout<<endl;
    }

    return 0;
}