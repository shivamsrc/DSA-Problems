#include<bits/stdc++.h>
using namespace std;

// Right Rotate a LL (LC 61)

class ListNode {
    public:

    int val;
    ListNode* next;

    ListNode(int val1){
        val = val1;
        next = nullptr;
    }

    ListNode(int val1, ListNode* next1){
        val = val1;
        next = next1;
    }
};

ListNode* vectorToLL(vector<int> arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i=1; i<arr.size(); i++){
        ListNode* newNode = new ListNode(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}


//
ListNode* rotateRight(ListNode* head, int k) {
    if(!head || head->next == NULL) return head;

    ListNode* temp = head;

    // find the size of LL
    int size = 0;
    while(temp){
        temp = temp->next;
        size++;
    }

    // if k > size
    k = k % size;

    if(k==0) return head;

    temp = head;

    // finding the new tail => {1,2,3,4,5} and k=2 then the new tail will be 3.
    int cnt = 1;
    while(temp){
        if(cnt == size-k) break;
        temp = temp->next;
        cnt++;
    }

    ListNode* newHead = temp->next;                      // for the same example new head will be 4.
    temp->next = NULL;
    ListNode* newTemp = newHead;

    while(newTemp && newTemp->next){
        newTemp = newTemp->next;
    }

    newTemp->next = head;

    return newHead;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};

    ListNode* head = vectorToLL(arr);

    head = rotateRight(head, 2);

    //
    ListNode* temp = head;

    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }

    return 0;
}