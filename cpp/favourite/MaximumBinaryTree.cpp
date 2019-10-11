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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*>st;
        if(nums.empty()) return NULL;
        for(auto num : nums) {
            TreeNode*node = new TreeNode(num);
            if(st.empty()){
                st.push(node);
                continue;
            }
            if(num< st.top()->val) {
                st.top()->right = node;
                st.push(node);
            }else{
                while(!st.empty() && st.top()->val < num) {
                    node->left = st.top();
                    st.pop();
                }
                if(!st.empty()) st.top()->right = node;
                st.push(node);
            }
        }
        TreeNode* res;
        while(!st.empty()){
            res = st.top();
            st.pop();
        }
        return res;
    }
};