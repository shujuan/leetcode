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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        getTraversal(root, res, 0);
        return res;
    
    }
    
    void getTraversal(TreeNode*root, vector<vector<int>>& res, int level){
        
        if(res.size() <= level) res.push_back(vector<int>{root->val});
        else if(level%2) res[level].insert(res[level].begin(), root->val);
        else res[level].push_back(root->val);
        
        if(root->left) getTraversal(root->left, res, level+1);
        if(root->right) getTraversal(root->right, res, level+1);
    }
    
    
};