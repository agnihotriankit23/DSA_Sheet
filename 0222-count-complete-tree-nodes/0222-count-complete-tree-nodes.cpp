/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        
        int left_count = 1;
        TreeNode* l = root->left;
        while(l)
        {
            left_count++;
            l= l->left;
        }
        int right_count = 1;
        TreeNode* r = root->right;
        while(r)
        {
            right_count++;
            r = r->right;
        }
        
        if(left_count == right_count)
        {
            return pow(2,left_count) -1;
            
        }
        
        return 1 +  countNodes(root->left) + countNodes(root->right);
        
    }
};