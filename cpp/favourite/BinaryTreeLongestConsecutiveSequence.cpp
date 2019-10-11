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
    int longestConsecutive(TreeNode* root) {
        return getMax(root, 0);
        
    }
    
    int getMax(TreeNode* root, int len) {
        if(!root) return 0;
        len++;
        int leftLen =0, rightLen=0;
        if(root->left){
            leftLen = getMax(root->left, root->left->val == root->val+1 ? len :0);
        }
        if(root->right){
            rightLen = getMax(root->right, root->right->val == root->val+1 ? len : 0);
        }
        
        return max(len, max(leftLen, rightLen));
        
    }
    
};