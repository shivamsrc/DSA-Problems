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

// reverse the node not just values

// if only data is to be reverse
Node* reverseDLL(Node* head){
    Node* temp = head;

    Node* left = head;
    Node* right = nullptr;
    int cnt = 0;

    while(temp){
        cnt++;
        right = temp;
        temp = temp->next;
    }

    // left = head, right = last node
    for(int i=1; i<=(cnt/2); i++){
        int hold = left->data;
        left->data = right->data;
        right->data = hold;

        left = left->next;
        right = right->back;

    }

    return head;
}

// reverse the whole node
Node* reverseDLL2(Node* head){
    if(!head || head->next == NULL){
        return head;
    }
    
    Node* prev = nullptr;
    Node* curr = head;
    while(curr){
        prev = curr->back;
        curr->back = curr->next;
        curr->next = prev;

        curr = curr->back;
    }

    return prev->back;
}


int main(){
    vector<int> arr = {1,2,3,4};

    Node* ans = ArrToDLL(arr);

    ans = reverseDLL2(ans);


    // Traverse
    Node* temp = ans;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

    return 0;
}