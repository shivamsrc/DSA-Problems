#include<bits/stdc++.h>
using namespace std;

// Integer to Roman
// Given: I = 1, IV = 4, V = 5, IX = 9, X = 10, XL = 40, L = 50, XC = 90, C = 100, CD = 400, D = 500, CM = 900, M = 1000


string intToRoman(int num) {
    int n = num;

    static vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static vector<string> sym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string result = "";

    for(int i=0; i<val.size(); i++){
        if(n == 0) break;

        if(val[i] <= n){
            int times = n / val[i];
            while(times--){
                result += sym[i];
            }
            n = n % val[i];
        }
    }

    return result;

}

int main(){
    int num = 1070;

    cout<<intToRoman(num);

    return 0;
}