#include<bits/stdc++.h>
using namespace std;

// Remove duplicates from sorted DLL

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
ListNode* removeDuplicates(ListNode *head) {
    if(!head || head->next == NULL) return head;

    ListNode* curr = head->next;

    while(curr){
        ListNode* last = curr->prev;

        if(curr->val == last->val){
            last->next = curr->next;

            if(curr->next){
                curr->next->prev = last;
            }
            delete curr;
            curr = last->next;
        }
        else{
            curr = curr->next;
        }
    }

    return head;
}

int main(){
    vector<int> arr = {1,1,1,2,3,3,4};

    ListNode* head = convertToDLL(arr);

    head = removeDuplicates(head);

    // Traversal
    ListNode* temp = head;
    
    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }

    return 0;
}