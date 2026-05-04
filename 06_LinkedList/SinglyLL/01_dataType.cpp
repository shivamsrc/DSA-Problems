#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node* next;

    // constructor
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // we can have multiple constructors
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    Node* y = new Node(2, nullptr);

    cout<<y<<endl;
    cout<<y->data;


    return 0;
}