#include<bits/stdc++.h>
using namespace std;

// Find Pairs with Given Sum in sorted Doubly Linked List with distinct positive integer

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

// Brute [O(n^2), O(1)]
vector<vector<int>> findPairsWithGivenSum2(ListNode* head, int target) {
    ListNode* temp = head;
    vector<vector<int>> ans;

    while(temp && temp->next){
        ListNode* temp2 = temp->next;

        while(temp2){
            int sum = temp->val + temp2->val;
            if(sum == target){
                ans.push_back({temp->val, temp2->val});
                temp2 = temp2->next;
            }
            else if(sum > target){
                break;
            }
            else{
                temp2 = temp2->next;
            }
        }

        temp = temp->next;
    }

    return ans;
}

// Optimal
vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target){
    ListNode* left = head;
    ListNode* right = head;
    vector<vector<int>> ans;

    while(right && right->next){
        right = right->next;
    }

    while(left->val < right->val){
        int sum = left->val + right->val;
        if(sum == target){
            ans.push_back({left->val, right->val});
            left = left->next;
            right = right->prev;
        }
        else if(sum > target){
            right = right->prev;
        }
        else if(sum < target){
            left = left->next;
        }
    }

    return ans;
}


int main(){
    vector<int> arr = {1,2,3,4,5};

    ListNode* head = convertToDLL(arr);

    vector<vector<int>> ans = findPairsWithGivenSum(head, 4);

    for(auto it : ans){
        cout<<it[0]<<" "<<it[1]<<endl;
    }

    return 0;
}