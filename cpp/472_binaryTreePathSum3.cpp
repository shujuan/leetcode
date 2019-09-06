/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum3(ParentTreeNode * root, int target) {
        // write your code here
        vector<vector<int>>res;
        pathSum(root, target, res);
        return res;
    }
    
    void pathSum(ParentTreeNode* root, int target, vector<vector<int>>& res) {
        if(!root) return;
        vector<int>path;
        getSum(root, nullptr, target, path, res);
        pathSum(root->left, target, res);
        pathSum(root->right, target, res);
    }
    
    void getSum(ParentTreeNode*root, ParentTreeNode* pre, int target,vector<int>&path, vector<vector<int>>& res ) {
       
       path.push_back(root->val);
       target -= root->val;
       if(target==0) {
            res.push_back(path);
            //return;
        }
        //if(target <0) return;
        
        
        if(root->left &&root->left != pre ){
            getSum(root->left, root, target, path, res);
        }
        
        if(root->right && root->right != pre) {
            getSum(root->right, root, target, path, res);
        }
        
        if(root->parent && root->parent != pre) {
            getSum(root->parent, root, target, path, res);
        }
        
        path.pop_back();
        
    }
};
