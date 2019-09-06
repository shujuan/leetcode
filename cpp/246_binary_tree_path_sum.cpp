/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
    int t;
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        // write your code here
        vector<vector<int>>res;
        vector<int>tmp;
        
        if(!root) return res;
        int t = target;
        vector<vector<int>> leftVec = binaryTreePathSum2(root->left, target);
        vector<vector<int>> rightVec = binaryTreePathSum2(root->right, target);
        getSet(res, target, tmp, root);
         res.insert(res.end(), leftVec.begin(), leftVec.end());
         res.insert(res.end(), rightVec.begin(), rightVec.end());
        return res;
    }
    
    void getSet(vector<vector<int>>& res, int target, vector<int>& tmp, TreeNode* root) {
       
        if(!root ) return;
       
     
        
        tmp.push_back(root->val);
         if(target == root->val) {
            res.push_back(tmp);
            //return;
        }
        getSet(res, target-root->val, tmp, root->left);
        getSet(res, target-root->val, tmp, root->right);
        tmp.pop_back();
        
        
        
       
        
        
    }
};
