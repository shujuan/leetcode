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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        res.push_back(root->val);
        getboundary(root->left, res, true, false);
        getboundary(root->right, res, false, true);
        return res;
    }
    
    void getboundary(TreeNode* node, vector<int>& res, bool lb, bool rb) {
        if(!node) return;
        if(lb) res.push_back(node->val);
        if(!lb && !rb && !node->left && !node->right) res.push_back(node->val);
        getboundary(node->left, res, lb, rb && !node->right);
        getboundary(node->right, res, lb & !node->left, rb);
        if(rb) res.push_back(node->val);
    }
};