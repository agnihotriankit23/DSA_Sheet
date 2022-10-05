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
    void solve(TreeNode* root,int level,int val,int depth){
        if(root==NULL)
            return ;
        
        if(level+1 == depth){
            TreeNode* newNode1 = new TreeNode(val);
            newNode1->left = root->left;
            TreeNode* newNode2 = new TreeNode(val);
            newNode2->right = root->right;
            root->left = newNode1;
            root->right = newNode2;
            return;
        }
        solve(root->left,level+1,val,depth);
        solve(root->right,level+1,val,depth);
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        solve(root,1,val,depth);
        return root;
    }
};