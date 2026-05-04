#include<bits/stdc++.h>
using namespace std;

// delete operation in LL 

// DataType
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

// Array to LL
ListNode* arrayToLL(vector<int> arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for(int i=1; i<arr.size(); i++){
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}


// DELETE HEAD OF THE LL
ListNode* deleteHead(ListNode* head) {
    if(!head) return nullptr;

    ListNode* temp = head;
    head = head->next;
    delete temp;

    return head;
}

// DELETE LAST OF THE LL
ListNode* deleteLast(ListNode* head){
    if(!head) return nullptr;
    if(head->next == NULL){
        delete head;
        return nullptr;
    }

    ListNode* temp = head;

    while(temp->next->next != NULL){                       // will run till 3rd last where temp will become 2nd last
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}


// DELETE Kth ELEMENT OF LL --> look all the edge cases like if it's the 1st element, last element or any in between at kth position.
ListNode* deleteK(ListNode* head, int k){
    if(!head) return nullptr;

    if(k <= 0) return head;

    // if k=1 and there's only one node in the LL
    if(k==1 && head->next == NULL){
        delete head;
        return nullptr;
    }

    // if k=1
    if(k==1){
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    //
    int cnt = 0;
    ListNode* temp = head;
    ListNode* kPrev = nullptr;                                 // immediate previous element of the kth element that's given (if matches then it'll be assigned). If the last element is needed to be deleted then this will be second last.
    while(temp){
        cnt++;
        if(cnt + 1 == k){
            kPrev = temp;
        }
        temp = temp->next;
    }

    // if k > lenght of the list
    if(k > cnt){
        return head;
    }

    // if k = cnt, means last element
    if(k == cnt){
        delete kPrev->next;
        kPrev->next = nullptr;
        return head;
    }

    // if k is between first and last element
    ListNode* temp1 = kPrev->next;
    kPrev->next = kPrev->next->next;
    delete temp1;
    return head;
}

// DELETE Kth ELEMENT OF LL (LC 237) --> Here the node is given that needs to be deleted and no head is given. so we copy the value of the next node and also the next's next and delete the node->next.
void deleteNode(ListNode* node) {
    if(node->next->next == NULL){
        node->val = node->next->val;
        delete node->next;
        node->next = nullptr;
    }
    else{
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
}

// DELETE NODE BASED ON GIVEN VALUE
ListNode* deleteVal(ListNode* head, int val){
    if(!head) return nullptr;

    if(head->val == val){
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* temp = head;
    ListNode* prev = nullptr;
    while(temp){
        if(temp->val == val){
            if(temp->next == NULL){
                prev->next = nullptr;
                delete temp;
                return head;
            }
            else{
                prev->next = temp->next;
                delete temp;
                return head;
            }
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};

    ListNode* head = arrayToLL(arr);

    head = deleteHead(head);                                            // either update the head or use call by reference in the function

    head = deleteLast(head);

    // we've {2,3,4,5,6}
    head = deleteK(head, 4);

    // we've {2,3,4,6}
    head = deleteVal(head, 2);

    // Traverse
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }

    return 0;
}