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
    TreeNode* predecessor = nullptr;
public:
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        // write your code here
        getPre(root, p);
        return predecessor;
    }
    
    TreeNode* getPre(TreeNode* root, TreeNode* p) {
        if(!root) return nullptr;
        getPre(root->left, p);
        if(root->val < p->val) predecessor = root;
        getPre(root->right, p);
    }
};
