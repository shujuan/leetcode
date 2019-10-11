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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int res =0;
        getPath(root, sum, res);
        return  res + pathSum(root->left, sum) +pathSum(root->right, sum);
    }
    
    void getPath(TreeNode* root, int sum, int& res) {
        if(!root)  return;
        sum -= root->val;
        if(sum==0) {
            res++;
        }
        getPath(root->left, sum, res);
        getPath(root->right, sum, res);
    }
};