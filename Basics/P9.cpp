#include<bits/stdc++.h>
using namespace std;

// RECURSION

// printing first "N" numbers
int cnt = 1;
void printNum(int n){
    //base condition
    if(cnt > n) return;

    cout << cnt << endl;
    cnt++;

    printNum(n);
}

// print name 'n' times
void printName1(string s, int x, int y){
    if(x>y) return;
    cout<<s<<endl;
    printName1(s, x+1, y);
}

// print name 'n' times without starting index
void printName2(string s, int n){
    if(n==0) return;
    cout<<s<<endl;
    printName2(s, n-1);
}

// print 1 to 'N' number without global variable
void printNums(int x, int y){
    if(x > y) return;
    cout<<x<<endl;
    printNums(x+1, y);
}

//print 'N' to 1
void reverseNum(int n){
    if(n==0) return;
    cout<<n<<endl;
    reverseNum(n-1);
}

// print linearly 1 to N using backtracking
void printNums2(int n){
    if(n==0) return;
    printNums2(n-1);
    cout<<n<<endl;
}

// print linearly N to 1 using backtracking
void printNums3(int x, int y){
    if(x > y) return;
    printNums3(x+1, y);
    cout<<x<<endl;
}

// sum of first 'N' numbers (parametrised way)
void printSum(int n, int sum){
    if(n==0){
        cout<<sum;
        return;
    }
    printSum(n-1, sum+n);
}

// sum of first 'N' numbers (functional way -> return the value)
int printSum2(int n){
    if(n==0) return 0;
    return n + printSum2(n-1);
}

// factorial of 'n'
int factorial(int n){
    if(n==0) return 1;
    return n * factorial(n-1);
}

// reverse an array
void reverseArr(int i, int n, int arr[]){
    if(i >= n/2) return;
    swap(arr[i], arr[n-i-1]);                 // swap(arr[0], arr[5-0-1 = 4])
    reverseArr(i+1, n, arr);
}

// palindrome string 
bool palindromeString2(string &s, int i=0){
    if(i == 0){
        string result = "";
        for(char c : s){
            if(isalnum(c)) result += tolower(c);
        }
        s = result;
    }
    if(i >= s.length()/2) return true;
    if(s[i] != s[s.length() -i -1]) return false;

    return palindromeString2(s, i+1);
}

// fibonacci series
int fib(int n){
    if(n==0 || n==1) return n;
    int last = fib(n-1);
    int secondLast = fib(n-2);

    return last + secondLast;
}

int main(){
    cout<<fib(6);
}