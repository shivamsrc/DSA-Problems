#include<bits/stdc++.h>
using namespace std;

// Reverse Nodes in K group in LL (LC 25)

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(){
        val = 0;
        next = nullptr;
        prev = nullptr;
    }

    ListNode(int val1, ListNode* next1, ListNode* prev1){
        val = val1;
        next = next1;
        prev = prev1;
    }

    ListNode(int val1){
        val = val1;
        next = nullptr;
        prev = nullptr;
    }

};

ListNode* convertToDLL(vector<int> arr){
    ListNode* head = new ListNode(arr[0]);

    ListNode* temp = head;

    for(int i=1; i<arr.size(); i++){
        ListNode* currNode = new ListNode(arr[i], nullptr, temp);

        temp->next = currNode;
        temp = temp->next;
    }

    return head;
}

//
ListNode* findKth(ListNode* head, int k){
    ListNode* temp = head;
    int cnt = 1;
    while(temp){
        if(cnt == k) return temp;
        temp = temp->next;
        cnt++;
    }

    return nullptr;
}

void reverseNode(ListNode* &head){
    ListNode* temp = head->next;
    head->next = NULL;
    ListNode* prevNode = head;

    while(temp){
        ListNode* nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
    }

}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;

    ListNode* nextNode = nullptr;
    ListNode* prevNode =  nullptr;

    while(temp){
        // find kth/ last element of the group
        ListNode* kth = findKth(temp, k);

        // if no kth element that means group is short of some element so leave it
        if(kth == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }

        nextNode = kth->next;                  // first element of the next group

        kth->next = NULL;                      // making the group independent to reverse it.

        reverseNode(temp);

        // if it's the first group then change the head
        if(temp==head){
            head = kth;
        }
        else{
            prevNode->next = kth;                           // connected the last element of the last group to the head of the current group after reversal
        }

        // temp after reversal will be the last element in a group so made it previous node.
        prevNode = temp;
        temp = nextNode;

    }

    return head;
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7};

    ListNode* head = convertToDLL(arr);

    head = reverseKGroup(head, 2);

    // Traversal
    ListNode* temp = head;
    
    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }

    return 0;
}