// user input-output 

#include<iostream>
using namespace std;

class Solution {
public:
    void printNumber(int num) {
        cout<<num;
    }
};

int main(){
    int num;
    cout<<"enter the number";
    cin>>num;
    Solution obj1;
    obj1.printNumber(num);
}