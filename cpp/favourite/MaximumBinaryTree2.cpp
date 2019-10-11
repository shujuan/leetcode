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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode*tmp = root;
        TreeNode* pre = nullptr;
        while(val < tmp->val) {
            if(tmp->right) {
                pre = tmp;
                tmp = tmp->right;
            }
            else{
                tmp->right = node;
                return root;
            }
        }
        if(pre) pre->right = node;
        node->left = tmp;
        return pre ? root : node;
        
    }
};