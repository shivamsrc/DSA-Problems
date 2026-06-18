#include<bits/stdc++.h>
using namespace std;

// Generate Parentheses (LC 22)

bool isValid(string s){
    int cnt = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            cnt++;
        }
        else{
            cnt--;
        }

        if(cnt<0) return false;
    }

    return cnt==0 ? true : false;
}

void GP(vector<string> &ans, string &s, int n){
    if(s.size() == 2*n){
        if(isValid(s)) ans.push_back(s);
        return;
    }

    s.push_back('(');
    GP(ans, s, n);
    s.pop_back();

    s.push_back(')');
    GP(ans, s, n);
    s.pop_back();
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;

    string s;

    GP(ans, s, n);

    return ans;
}

int main(){
    vector<string> ans = generateParenthesis(2);

    for(auto it : ans){
        for(auto x : it){
            cout<<x;
        }
        cout<<endl;
    }
    

    return 0;
}