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


// DELETE HEAD
Node* deleteHead(Node* head){
    if(!head) return nullptr;

    if(head->next == NULL){
        delete head;
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    delete temp;

    return head;
}

// DELETE TAIL
Node* deleteTail(Node* head){
    if(!head) return nullptr;

    if(head->next == NULL){
        delete head;
        return nullptr;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // at the end temp will be at last and prev will be pointing second last
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;
    delete temp;

    return head;
}

// DELETE Kth
Node* deleteKth(Node* head, int k){
    if(!head || k<=0 ) return head;

    if(k==1 && head->next == NULL){
        delete head;
        return nullptr;
    }

    if(k==1){
        Node* temp = head;
        head = head->next;
        head->back = nullptr;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt == k){
            // if k is tail
            if(temp->next == NULL){
                prev->next = nullptr;
                delete temp;
                return head;
            }

            Node* tempNode = temp;
            prev->next = temp->next;
            temp = temp->next;
            temp->back = prev;
            delete tempNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    if(k > cnt) return head;

    return head;
}

// DELETE GIVEN NODE (given node can't be head or tail)
void deleteNode(Node* node){
    // can't delete if the node is null or node is the last node
    if(!node || node->next == NULL) return;

    Node* temp = node->next;

    node->data = temp->data;
    node->next = temp->next;

    if(temp->next != NULL){
        temp->next->back = node;
    }

    delete temp;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};

    Node* ans = ArrToDLL(arr);

    ans = deleteHead(ans);

    ans = deleteTail(ans);

    // we've {2,3,4,5,6}
    ans = deleteKth(ans, 1);


    // Traverse
    Node* temp = ans;
    while(temp){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

    return 0;
}