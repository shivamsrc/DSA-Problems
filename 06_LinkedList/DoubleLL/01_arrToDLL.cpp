#include<bits/stdc++.h>
using namespace std;

// Data type
class Node {
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* back1, Node* next1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* ArrToDLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], prev, nullptr);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    Node* ans = ArrToDLL(arr);


    // Traverse
    Node* temp = ans;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

    return 0;
}