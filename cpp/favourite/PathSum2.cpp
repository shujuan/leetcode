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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>tmp;
        getPath(root, sum, tmp, res);
        return res;   
    }
    
    void getPath(TreeNode* root, int sum, vector<int>& tmp, vector<vector<int>>& res) {
        
     
        if(!root ) 
            return;
        tmp.push_back(root->val);
        sum -= root->val;
        if(sum == 0 && !tmp.empty() && !root->left && !root->right) {
            res.push_back(tmp);
            //return;
        } 
        getPath(root->left, sum, tmp, res);
        getPath(root->right, sum, tmp, res);
        tmp.pop_back();
        
        
    }
};