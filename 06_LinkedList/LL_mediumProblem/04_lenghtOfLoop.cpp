#include<bits/stdc++.h>
using namespace std;

// find the lenght of loop or cycle in the LinkedList

// DataType

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute
int cycleLenght(ListNode *head) {
    ListNode* temp = head;
    
    map<ListNode*, int> mp;
    int t = 0;

    while(temp){
        if(mp.find(temp) != mp.end()){
            return t - mp[temp];
        }
        else{
            mp.insert({temp, t});
            t++;
            temp = temp->next;
        }
    }

    return 0;
}

int cycleLenght2(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = slow->next;
            int cnt = 1;
            while(slow != fast){
                cnt++;
                slow = slow->next;
            }
            return cnt;
        }
    }

    return 0;
}


int main(){

    return 0;
}