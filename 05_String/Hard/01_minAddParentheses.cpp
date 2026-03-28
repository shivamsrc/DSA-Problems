#include<bits/stdc++.h>
using namespace std;

// Minimum Add to Make Parentheses Valid (LC 921)
// ()) --> 1, ((( --> 3, ))()(( --> 4

int minAddToMakeValid(string s) {
    int n = s.size();

    if(n == 0) return 0;

    int countL = 0, countR = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            countL++;
        }
        else if(s[i] == ')' && countL==0){
            countR++;
        }
        else if(s[i] == ')'){
            while(countL > 0 && s[i]==')'){
                i++;
                countL--;
            }
            i--;
        }
    }

    return countL+countR;
}

int main(){
    string s = "(()())())(()";

    cout<<minAddToMakeValid(s);

    return 0;
}