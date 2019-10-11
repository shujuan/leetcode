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
    set<int>data;
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        if(data.count(root->val))return true;
        data.insert(k-root->val);
        return findTarget(root->left,k)||findTarget(root->right,k);
        
        
    }
};