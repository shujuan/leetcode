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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int res = getkthSmallest(root, k, cnt);
        return res;
        
    }
    
    int getkthSmallest(TreeNode* root, int k, int& cnt) {
        if (!root) return 0;
        int res;
        res = getkthSmallest(root->left, k, cnt);
        if (cnt == k) return res;
        cnt++;
        if (cnt == k) return root->val;
        res = getkthSmallest(root->right, k, cnt);
        return res;
    }
};