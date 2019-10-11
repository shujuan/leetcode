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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return getTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* getTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps > pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int pos = is;
        for (int i= is; i<=ie; i++) {
            if(inorder[i] == preorder[ps]) {
                pos = i;
                break;
            }
        }
        
        int left_len = pos - is;
        int right_len = ie- pos;
        
        root->left = getTree(preorder, inorder, ps+1, ps+left_len, is, pos-1);
        root ->right = getTree(preorder, inorder, ps+left_len+1, pe, pos+1, ie);
        return root;
    }
};