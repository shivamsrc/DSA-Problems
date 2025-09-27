// pass by value and pass by reference

#include<iostream>
using namespace std;

// pass by value - copy is passed
void doSomething(int num){
    cout<<num<<endl;
    num += 10;
    cout<<num<<endl;
    num += 10;
    cout<<num<<endl;
}

// pass by reference - actual variable is passed
void doSomething2(int &num){
    cout<<num<<endl;
    num += 10;
    cout<<num<<endl;
    num += 10;
    cout<<num<<endl;
}

int main(){
    int num = 100;

    doSomething(num);
    cout<<num<<endl<<endl;

    doSomething2(num);
    cout<<num;
}