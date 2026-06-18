#include<bits/stdc++.h>
using namespace std;

// Expression Add Operators (LC 282)
// check code concepts with animesh on yt

// i => it basically tells how many digits from string s has been included in the path.
// path => it's the answer string that we are building. we took it as const because for passing by reference we can't do some operation and pass it as argument. but with const we can do this for reference variable as well.
// eval => the answer that we have got by evaluting the digits till now.
// prev => it's the digit or the last digit from the path. our current will be prev for the next call.

vector<string> ans;

void helper(string s, int target, int i, const string &path, long eval, long prev){
    if(i == s.size()){
        if(eval == target){
            ans.push_back(path);
            return;
        }
    }

    string currStr;                         // we'll build this string here and eventually will add to path and send to the next call as path.
    long num = 0;

    // this loop will run for whatever the part remaining from the main string s. like if we've 128 and path is "1" then this loop is gonna run for "28" and if path is "12" then it's gonna run for "8" etc.
    // i represents the no. of digits that has been included in the path so j=i means we're gonna evalute the remaining parts now.

    for(int j=i; j<s.size(); j++){
        // handle 0
        if(j>i && s[i]=='0') return;

        currStr += s[j];
        num = num*10 + (s[j] - '0');

        // this means that we're taking the first digit so can't apply any operator because there's no other digit or eval to be applied with so here eval = num and prev = num.
        if(i==0){
            helper(s, target, j+1, path + currStr, num, num);
        }
        else{
            helper(s, target, j+1, path + "+" + currStr, eval+num, num);
            helper(s, target, j+1, path + "-" + currStr, eval-num, -num);
            helper(s, target, j+1, path + "*" + currStr, eval-prev + prev*num, prev*num);       // let' undertand this ("128"): let we had, path = "1+2", currStr = "8", eval = 3, num=8, prev=2 so now the new path will be "1+2*8" and the correct answer of this is 17. But, if we do eval*num = 3*8 = 24 which is wrong. so first of all we'll remove the prev digit which according to bodmas should be multiplied with num, from eval. so (eval-prev) + (prev*num) = (3-2) + (2*8) = 1+16 = 17.
        }

    }
}

vector<string> addOperators(string num, int target) {
    helper(num, target, 0, "", 0, 0);
    return ans;
}

int main(){

    return 0;
}