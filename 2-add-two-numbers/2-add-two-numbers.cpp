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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode();
        int carry = 0;
        ListNode* temp = ans;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->val + temp2->val + carry;
            ListNode* newNode = new ListNode((sum%10));
            sum=sum/10;
            carry = sum;
            temp->next = newNode;
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
             int sum = temp1->val +  carry;
            ListNode* newNode = new ListNode((sum%10));
            sum=sum/10;
            carry = sum;
            temp->next = newNode;
            temp=temp->next;
            temp1=temp1->next;
        }
         while(temp2){
             int sum = temp2->val +  carry;
            ListNode* newNode = new ListNode((sum%10));
            sum=sum/10;
            carry = sum;
            temp->next = newNode;
            temp=temp->next;
            temp2=temp2->next;
        }
        if(carry!=0){
             ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return ans->next;
        
    }
};