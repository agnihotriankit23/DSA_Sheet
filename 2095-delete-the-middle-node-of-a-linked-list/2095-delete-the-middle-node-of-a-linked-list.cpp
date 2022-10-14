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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt==0){
            return head;
        }else if(cnt==1){
            return NULL;
        }else if(cnt==2){
            head->next=NULL;
            return head;
        }
        cout<<cnt<<endl;
        int mid = cnt/2;
        int n = cnt;
        // if(n%2){
        //     mid = n/2;
        // }else{
        //     mid = n/2 +1;
        // }
        temp=head;
        ListNode* prv = NULL;
        for(int i=1;i<=mid;i++){
            prv = temp;
            temp=temp->next;
        }
        
        cout<<temp->val<<endl;
        prv->next = temp->next;
        return head;
    }
};