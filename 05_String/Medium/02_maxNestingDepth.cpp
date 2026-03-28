#include<bits/stdc++.h>
using namespace std;

// Maximum Nesting Depth of the Parentheses (LC 1614)
// (1+(2*3)+((8)/4))+1 --> 3

// Optimal
int maxDepth(string s) {
    int n = s.size();

    int maxi = 0;

    int check = 0;

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            check++;
        }
        else if(s[i] == ')'){
            check--;
        }

        maxi = max(maxi, check);
    }

    return maxi;
}

int main(){
    string str = "(1+(2*3)+((8)/4))+1";

    cout<<maxDepth(str);

    return 0;
}