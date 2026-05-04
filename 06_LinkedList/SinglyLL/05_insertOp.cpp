#include<bits/stdc++.h>
using namespace std;

// Insertion operation in LL 

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



// INSERT A NEW NODE AT HEAD
ListNode* insertHead(ListNode* head, int val){
    ListNode* temp = new ListNode(val, head);
    return temp;
}

// INSERT AT THE LAST
ListNode* insertLast(ListNode* head, int val){
    ListNode* temp = head;

    while(temp->next != NULL){                      // temp at the end will be pointer to the last node
        temp = temp->next;
    }

    ListNode* newNode = new ListNode(val);
    temp->next = newNode;
    return head;
}

// INSERT AT Kth POSITION
ListNode* insertK(ListNode* head, int k, int val){
    ListNode* temp = head;

    // insert at first
    if(k == 1){
        ListNode* newNode = new ListNode(val, temp);
        return newNode;
    }

    // insert at k
    int cnt = 0;
    ListNode* prev = nullptr;

    while(temp){
        cnt++;
        if(cnt == k){
            ListNode* newNode = new ListNode(val, temp);
            prev->next = newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    // insert at last (at the end prev will be last)
    if(k == cnt+1){
        ListNode* newNode = new ListNode(val);
        prev->next = newNode;
        return head;
    }

    return head;
}

// INSERT A NODE BEFORE THE GIVEN VALUE
ListNode* insertBeforeVal(ListNode* head, int before, int val){
    ListNode* temp = head;

    // insert at first
    if(temp->val == before){
        ListNode* newNode = new ListNode(val, temp);
        return newNode;
    }

    //
    ListNode* prev = nullptr;
    while(temp){
        if(temp->val ==  before){
            ListNode* newNode = new ListNode(val, temp);
            prev->next = newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    ListNode* head = arrayToLL(arr);

    head = insertHead(head, 49);

    head = insertLast(head, 99);

    // we've {49,1,2,3,4,5,99}
    head = insertK(head, 2, 10);

    // we've {49, 10, 1, 2, 3, 4, 5, 99}
    head = insertBeforeVal(head, 2, 777);

    // Traverse
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }

    return 0;
}