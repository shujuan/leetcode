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
    vector<int> preorderTraversal(TreeNode* root) {
//       看答案之前
//         vector<int> res;
//         if(!root) return res;
//         res.push_back(root->val);
//         stack<TreeNode*>st;
//         st.push(root);
//         while(root->left){
//                 res.push_back(root->left->val);
//                 st.push(root->left);
//                 root = root->left;
//         }
//         while(!st.empty()) {
           
//             auto tmp = st.top();
//             st.pop();
//             if(tmp->right) {
//                 res.push_back(tmp->right->val);
//                 st.push(tmp->right);
//                 tmp = tmp->right;
//                 while(tmp->left){
//                     res.push_back(tmp->left->val);
//                     st.push(tmp->left);
//                     tmp = tmp->left;
//                 }
                
//             }
            
//         }
//         return res;
//看答案之后
        stack<TreeNode*>st;
        vector<int>res;
        if(!root) return res;
        st.push(root);
        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            res.push_back(top->val);
            if(top->right) st.push(top->right);
            if(top->left)  st.push(top->left);
        }
        return res;
            
    }
    
    
};
