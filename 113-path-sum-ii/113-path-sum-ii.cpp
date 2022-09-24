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
    void inorder(TreeNode* root,vector<int> e,vector<vector<int>> &paths){
        if(root==NULL){
              
            return;
        }
           
        //cout<<root->val<<" ";
        e.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
    {
        paths.push_back(e);
    }
    else
    {
        
       inorder(root->left,e,paths);
        
        inorder(root->right,e,paths);
    }
        
       
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
         vector<vector<int>> paths;
        vector<int> elements;
        
        inorder(root,elements,paths);
        for(auto i:paths){
            int sum=0;
            for(auto j:i){
                cout<<j<<" ";
                sum+=j;
            }cout<<endl;
            if(sum==targetSum)
                ans.push_back(i);
        }
       
        return ans;
    }
};