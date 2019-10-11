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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL;
        if(!root) return nullptr;
     
            if(root->val > p->val){
                res = inorderSuccessor(root->left, p);
            } else {
                res = inorderSuccessor(root->right,p);
            }
        
        return (res == nullptr && root->val > p->val) ? root : res;
        
        
    }
    
 
};