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
    int maxLen =0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        getMaxLen(root);
        return maxLen-1;
        
    }
    
    int getMaxLen(TreeNode* root) {
        if(!root) return 0;
        int leftLen = getMaxLen(root->left);
        int rightLen = getMaxLen(root->right);
        maxLen =  max(maxLen, leftLen+rightLen+1);
        return max(leftLen, rightLen) +1;
    }
};