#include<bits/stdc++.h>
using namespace std;

// Sort a LinkedList of 0's, 1's and 2's

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

// Approach - 1
ListNode* sortList(ListNode* head){
    ListNode* temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    while(temp){
        if(temp->val == 0){ cnt0++; temp=temp->next;}
        else if(temp->val == 1){ cnt1++; temp=temp->next;}
        else {cnt2++; temp=temp->next;};
    }

    temp = head;
    while(temp){
        if(cnt0 > 0){
            temp->val = 0;
            cnt0--;
            temp = temp->next;
        }
        else if(cnt1 > 0){
            temp->val = 1;
            cnt1--;
            temp = temp->next;
        }
        else{
            temp->val = 2;
            cnt2--;
            temp = temp->next;
        }
    }

    return head;
}

// Approach - 2 (changing links)
ListNode* sortList2(ListNode* head){
    ListNode* temp = head;

    ListNode* zHead = new ListNode(-1);                            // zero head
    ListNode* zTemp = zHead;

    ListNode* oHead = new ListNode(-1);                            // one head
    ListNode* oTemp = oHead;

    ListNode* tHead = new ListNode(-1);                            // two head
    ListNode* tTemp = tHead;

    while(temp){
        if(temp->val == 0){
            zTemp->next = temp;
            zTemp = temp;
            temp = temp->next;
        }
        else if(temp->val == 1){
            oTemp->next = temp;
            oTemp = temp;
            temp = temp->next;
        }
        else{
            tTemp->next = temp;
            tTemp = temp;
            temp = temp->next;
        }
    }

    zTemp->next = oHead->next;
    oTemp->next = tHead->next;
    tTemp->next = NULL;

    return zHead->next;
}

int main(){
    vector<int> arr = {2,0,1,1,2,0};

    ListNode* head = vectorToList(arr);

    head = sortList2(head);
    //
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<endl;
        temp = temp->next;
    }

    return 0;
}