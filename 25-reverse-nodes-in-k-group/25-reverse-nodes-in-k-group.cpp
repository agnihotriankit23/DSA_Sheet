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
        if(head==NULL || k==1)
            return head;
        
        int cnt = 0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt<k)
            return head;
        ListNode* prv = NULL;
        ListNode* curr=head;
        ListNode* nxt=NULL;
        int cnt1=0;
        while( cnt1<k && curr!=NULL){
            nxt = curr->next;
            curr->next=prv;
            prv=curr;
            curr=nxt;
            cnt1++;
        }
        if(curr!=NULL)
            head->next = reverseKGroup(nxt,k);
        
        
        return prv;
        
        
    }
};