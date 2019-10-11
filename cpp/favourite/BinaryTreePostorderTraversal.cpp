
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* cur = root;
        stack<TreeNode*>st;
        while(!st.empty() || cur) {
            if(cur) {
                st.push(cur);
                res.insert(res.begin(), cur->val);
                cur = cur->right;
            } else{
                auto top= st.top();
                st.pop();
                cur = top->left;
            }
        }
        
        return res;
    }
};