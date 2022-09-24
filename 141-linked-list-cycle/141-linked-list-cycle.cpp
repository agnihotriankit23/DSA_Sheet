/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mp;
        ListNode* temp = head;
        while(temp){
            if(mp[temp]==1)
                return 1;
            
            mp[temp]=1;
            temp=temp->next;
        }
        return 0;
    }
};