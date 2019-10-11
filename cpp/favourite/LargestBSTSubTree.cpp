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
    int largestBSTSubtree(TreeNode* root) {
        int res=0, mn = INT_MIN, mx= INT_MAX;
        getBSTSubtree(root, mn, mx, res);
        return res;
    }
    
    void getBSTSubtree(TreeNode* root, int& mn, int& mx, int& cnt) {
        if(!root) return;
        int left_cnt=0, right_cnt=0;
        int left_mn = INT_MIN, right_mn=INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
        getBSTSubtree(root->left, left_mn, left_mx, left_cnt);
        getBSTSubtree(root->right, right_mn, right_mx, right_cnt);
        if((!root->left||root->val>left_mx) && (!root->right ||root->val < right_mn)) {
            cnt = left_cnt +right_cnt+1;
            mn = root->left ? left_mn : root->val;
            mx = root->right ? right_mx : root->val;
        } else {
            cnt = max(left_cnt, right_cnt);
        }
    }
};