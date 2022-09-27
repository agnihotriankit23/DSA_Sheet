/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast->next!=NULL && fast->next->next!=NULL){
           slow = slow->next;
           fast = fast->next->next;
       }
        ListNode* revNode = slow->next;
        ListNode* prv = NULL;
        ListNode* curr= revNode;
        ListNode* nxt = NULL;
        
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prv;
            prv=curr;
            curr=nxt;
        }
        revNode=prv;
        slow->next = revNode;
        ListNode* temp = head;
        while(revNode!=NULL){
            if(revNode->val !=temp->val) return false;
            revNode=revNode->next;
            temp = temp->next;
        }
        return true;
    }
};