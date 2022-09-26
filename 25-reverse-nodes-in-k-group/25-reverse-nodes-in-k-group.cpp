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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        
        int len = 0;
        
        ListNode* temp=head;
        
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        
        ListNode* ans=new ListNode();
        ans->next=head;
        ListNode* prv = ans;  
        ListNode* curr;
        ListNode* nxt;
        
        while(len>=k){
            curr = prv->next;
            nxt = curr->next;
            for(int i=1;i<k;i++){
                curr->next = nxt->next;
                nxt->next = prv->next;
                prv->next = nxt;
                nxt = curr->next;
        }
        prv = curr;
        len -= k;
        }
        return ans->next;
    }
};