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
    //TreeNode* preNode = NULL;
public:
    void flatten(TreeNode* root) {
        //Method1
        // while(root) {
        //     if(root->left){
        //         auto tmp = root->left;
        //         while(tmp->right){
        //             tmp= tmp->right;
        //         }
        //         tmp->right = root->right;
        //         root->right = root->left;
        //         root->left = NULL;
        //     }
        //     root = root->right;
        // }
        
        //Method 2 Traverse;
//         if(!root) return;
//         if(preNode) {
//             preNode->right = root;
//             preNode->left = NULL;
//         }
        
//         preNode = root;
//         TreeNode* r= root->right;
//         flatten(root->left);
//         flatten(r);
        
        //Method3 stack
        stack<TreeNode*>st;
        if(!root) return;
        st.push(root);
        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            if(top->right){
                st.push(top->right);
            }
            
            if(top->left) {
                st.push(top->left);
            }
            
            top->left = NULL;
            if(!st.empty())top->right = st.top();
            //else top->right = NULL;
   
        }
        
        //method4 divide and conquer
        
    }
};