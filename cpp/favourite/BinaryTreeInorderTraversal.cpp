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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* pCur = root;
        while(!st.empty() || pCur) {
            if (pCur) {
                st.push(pCur);
                pCur = pCur->left;
            } else {
                TreeNode* t = st.top();
                st.pop();
                res.push_back(t->val);
                pCur = t->right;
                
            }
        }
        return res;
    }
   
};
