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
    pair<TreeNode*, int>minNode{nullptr, INT_MAX};
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        if(!root) return nullptr;
        getSum(root);
        
        return minNode.first;
        
    }
    
    int getSum(TreeNode* root){
        if(!root) return 0;
        int leftVal = getSum(root->left);
        int rightVal = getSum(root->right);
        if((leftVal+rightVal +root->val) <minNode.second){
            minNode = {root, leftVal+rightVal +root->val};
        }
        return leftVal+rightVal +root->val;
        
    }
};
