#include<bits/stdc++.h>
using namespace std;

// Add 1 to a number represented by LL

class ListNode {
    public:
    int val;
    ListNode* next;

    ListNode(int val1, ListNode* next1){
        val = val1;
        next = next1;
    }

    ListNode(int val1){
        val = val1;
        next = nullptr;
    }
};

ListNode* vectorToList(vector<int> arr){
    int n = arr.size();

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i=1; i<n; i++){
        ListNode* newNode = new ListNode(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

// Solution
// Add and Carry Method
ListNode* reverseLL(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while(curr){
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

ListNode* addOne(ListNode* head){
    ListNode* temp = head;

    ListNode* newHead = reverseLL(temp);
    ListNode* newTemp = newHead;
    int carry = 1;

    while(newTemp){
        if(newTemp->val == 9){
            newTemp->val = 0;
            carry = 1;
            newTemp = newTemp->next;
        }
        else{
            newTemp->val = newTemp->val + 1;
            carry = 0;
            break;
        }
    }

    temp = reverseLL(newHead);

    if(carry == 1){
        ListNode* newNode = new ListNode(1, head);
        return newNode;
    }

    return temp;
}

int main(){
    vector<int> arr = {9,9,9};

    ListNode* head = vectorToList(arr);

    head = addOne(head);

    //
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }

    return 0;
}