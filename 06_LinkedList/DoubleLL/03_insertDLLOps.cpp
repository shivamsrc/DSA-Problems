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


// INSERT BEFORE HEAD
Node* insertBeforeHead(Node* head, int val){
    if(!head){
        Node* temp = new Node(val);
        return temp;
    };

    Node* temp = new Node(val, nullptr, head);

    head->back = temp;

    return temp;
}

// INSERT BEFORE TAIL
Node* insertBeforeTail(Node* head, int val){
    if(!head){
        Node* temp = new Node(val);
        return temp;
    }

    if(head->next == NULL){
        Node* temp = new Node(val, nullptr, head);
        head->back = temp;
        return temp;
    }

    Node* temp = head;

    // at the end temp will be at 2nd last
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    Node* newNode = new Node(val, temp, temp->next);
    temp->next = newNode;
    newNode->next->back = newNode;


    return head;
}

// INSERT BEFORE KTH ELEMENT
Node* insertBeforeK(Node* head, int val, int k){
    if(!head && k==1){
        Node* temp = new Node(val);
        return temp;
    }

    if(k <= 0) return head;

    if(k==1){
        Node* temp = new Node(val, nullptr, head);
        head->back = temp;
        return temp;
    }

    Node* temp = head;
    Node* NodeK = nullptr;
    int cnt = 0;

    while(temp){
        cnt++;
        if(cnt == k){
            NodeK = temp;
            break;
        }
        temp = temp->next;
    }

    if(k > cnt) return head;

    Node* newNode = new Node(val, NodeK->back, NodeK);
    NodeK->back->next = newNode;
    NodeK->back = newNode;

    return head;
}

// INSERT BEFORE A GIVEN NODE (node will not be head)
void insertBeforeNode(Node* node, int val){
    if(!node){
        return;
    }

    Node* newNode = new Node(val, node->back, node);

    if(node->back){
        node->back->next = newNode;
    }
    node->back = newNode;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    Node* ans = ArrToDLL(arr);

    ans = insertBeforeHead(ans, 10);

    ans = insertBeforeTail(ans, 40);

    // we've {10,1,2,3,4,40,5}
    ans = insertBeforeK(ans, 99, 4);


    // Traverse
    Node* temp = ans;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

    return 0;
}