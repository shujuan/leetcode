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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res =INT_MIN;
        getMax(root, res);
        // maxPathSum(root->left);
        // maxPathSum(root->right);
        return res;
        
    }
    
    int getMax(TreeNode* root, int& res) {
        if(!root) return 0;
       
        int left = max(getMax(root->left, res),0);
        int right = max(getMax(root->right, res), 0);
       
        res = max(res, root->val+left+right);
        return root->val+max(left, right);
        
    }
    
};