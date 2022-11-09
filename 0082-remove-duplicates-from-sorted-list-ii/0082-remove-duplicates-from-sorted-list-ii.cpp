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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mp;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            mp[temp->val]++;
            temp=temp->next;
        }
        ListNode* ans = new ListNode();
        temp=ans;
        for(auto i:mp)
        {
            if(i.second==1)
            {
                ListNode* t = new ListNode(i.first);
                temp->next = t;
                temp=temp->next;
            }
        }
        return ans->next;
    }
};