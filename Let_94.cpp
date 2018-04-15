/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)return ans;
        
        if(root->left != NULL){
            for(auto& a : inorderTraversal(root->left)){
                ans.push_back(a);
            }
        }
        
        ans.push_back(root->val);
        
        if(root->right != NULL){
            for(auto& a : inorderTraversal(root->right)){
                ans.push_back(a);
            }
        }
        return ans;
    }
};