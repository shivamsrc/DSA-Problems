#include<bits/stdc++.h>
using namespace std;

// Remove Outermost Parenthesis (LC 1021) -->
// (()()) -> ()()
// (()(())) -> ()(())
// ()() -> ""

string removeOuterParentheses(string s) {
    int n = s.size();

    if(n==0) return s;

    int cnt = 0;                                  // if count is '0' that means either eats the outermost '(' or ')'
    string ans = "";

    for(int i=0; i<n; i++){
        if(cnt == 0){
            if(s[i] == '(') cnt++;
            else cnt --;
        }
            
        else if(s[i] == '('){
            cnt++;
            if(cnt == 0) continue;
            else ans = ans + s[i];
        }
        else{
            cnt--;
            if(cnt == 0) continue;
            else ans = ans + s[i];
        }
    }

    return ans;
}

int main(){
    string str = "(()())";

    cout<<removeOuterParentheses(str);

    return 0;
}