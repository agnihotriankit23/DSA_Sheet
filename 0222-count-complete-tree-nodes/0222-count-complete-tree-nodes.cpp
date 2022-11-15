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
    void solve(int &ans, TreeNode* root)
    {
        if(root== NULL)
        {
            return;
        }
        ans++;
        
        solve(ans,root->left);
        solve(ans,root->right);
        
    }
    
    int countNodes(TreeNode* root) {
        int ans = 0;
        solve(ans,root);
        return ans;
    }
};