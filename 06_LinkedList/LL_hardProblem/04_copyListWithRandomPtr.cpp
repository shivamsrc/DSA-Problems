#include<bits/stdc++.h>
using namespace std;

// Copy List with random pointer

class Node {
    public:
    int val;
    Node* next;
    Node* random;

    Node(int val1){
        val = val1;
        next = nullptr;
        random = nullptr;
    }

    Node(int val1, Node* random1){
        val = val1;
        next = nullptr;
        random = random1;
    }

    Node(int val1, Node* next1, Node* random1){
        val = val1;
        next = next1;
        random = random1;
    }
};

//
Node* copyRandomList2(Node* head) {
    Node* temp = head;
    map<Node*, Node*> mp;

    while(temp){
        Node* newNode = new Node(temp->val);
        mp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    while(temp){
        Node* cloneNode = mp[temp];

        cloneNode->next = mp[temp->next];
        cloneNode->random = mp[temp->random];

        temp = temp->next;
    }

    return mp[head];
}

//
Node* copyRandomList(Node* head){
    if(!head) return head;

    Node* temp = head;

    while(temp){
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }

    temp = head;

    while(temp){
        if(temp->random){
            temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        else{
            temp->next->random = nullptr;
            temp = temp->next->next;
        }
    }

    temp = head;
    Node* chead = head->next;
    Node* ctemp = head->next;

    while(temp){
        temp->next = temp->next->next;

        if(ctemp->next){
            ctemp->next = ctemp->next->next;
        }
        else{
            ctemp->next = nullptr;
        }
        temp = temp->next;
        ctemp = ctemp->next;
    }

    return chead;
}

int main(){

    return 0;
}