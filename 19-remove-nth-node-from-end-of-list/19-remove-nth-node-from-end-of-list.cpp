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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)
            return NULL;
        
        int cnt=0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
         if(cnt==n)
                return head->next;
        if(cnt==2){
            if(n==1){
                head->next=NULL;
                return head;
            }
            else 
                return head->next;
                
        }
        temp=head;
        cnt=cnt-n;
        ListNode* prv = head;
        while(cnt>0){
            cnt--;
            prv=temp;
            temp=temp->next;
        }
        cout<<prv->val<<" ";
        cout<<temp->val;
        prv->next = temp->next;
        delete(temp);
        return head;
    }
};