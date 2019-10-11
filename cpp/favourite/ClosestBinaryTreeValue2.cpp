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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int>res;
        getKValues(root, target, k, res);
        return res;
    }
    
    void getKValues(TreeNode*root, double target, int k, vector<int>&res) {
        if(!root)  return;
        getKValues(root->left, target, k, res);
        if(res.size() < k)  res.push_back(root->val);
        else if(abs(res[0]-target) > abs(root->val-target)) {
            res.erase(res.begin());
            res.push_back(root->val);
        } else return;
        getKValues(root->right, target, k, res);
    }
};