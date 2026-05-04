#include<bits/stdc++.h>
using namespace std;

// Delete all occurrences of a key in DLL

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
ListNode* deleteAllOccurrences(ListNode* head, int target) {
    if(!head) return head;

    ListNode* currNode = head;

    if(currNode->prev == NULL && currNode->next == NULL && currNode->val == target){
        delete currNode;
        return nullptr;
    }

    while(currNode){
        if(currNode->prev == NULL && currNode->val == target){
            ListNode* nextNode = currNode->next;
            nextNode->prev = currNode->prev;
            ListNode* temp = currNode;
            currNode = currNode->next;
            head = currNode;
            delete temp;
        }

        else if(currNode->next == NULL && currNode->val == target){
            ListNode* prevNode = currNode->prev;
            prevNode->next = currNode->next;
            ListNode* temp = currNode;
            currNode = currNode->next;
            delete temp;
        }

        else if(currNode->val == target){
            currNode->prev->next = currNode->next;
            currNode->next->prev = currNode->prev;
            ListNode* temp = currNode;
            currNode = currNode->next;
            delete temp;
        }
        else{
            currNode = currNode->next;
        }
    }

    return head;
}

int main(){
    vector<int> arr = {1,2,5};

    ListNode* head = convertToDLL(arr);

    head = deleteAllOccurrences(head,5);

    // Traverse
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }

    return 0;
}