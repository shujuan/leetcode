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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root == p) return p;
        if(root == q) return q;
        TreeNode* lf = lowestCommonAncestor(root->left, p, q);
        if(lf && lf !=p && lf!=q) return lf;
        TreeNode* rt = lowestCommonAncestor(root->right, p, q);
        if(lf && rt) return root;
        return lf? lf : rt;
    }
};