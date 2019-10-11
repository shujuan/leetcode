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
        if(!root) return 0;
        int res = getMax(root, 1) + getMax(root, -1) +1;
        return max(res, max(longestConsecutive(root->left), longestConsecutive(root->right)));
    }
    
    int getMax(TreeNode* root, int diff) {
        if(!root) return 0;
        int left =0, right=0;
        if(root->left && root->val -root->left->val == diff){
            left = getMax(root->left, diff) +1;
        }
        
        if(root->right && root->val- root->right->val == diff) {
            right = getMax(root->right, diff) +1;
        }
        
        return max(left, right);
    }
                   
   
};