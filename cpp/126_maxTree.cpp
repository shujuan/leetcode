/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode * maxTree(vector<int> &A) {
        // write your code here
        vector<TreeNode*>st;
        for(int i=0; i<A.size(); i++) {
            TreeNode* n = new TreeNode(A[i]);
            if(!st.empty() && A[i] > st.back()->val)
            {
                while(!st.empty() && st.back()->val < A[i]){
                    n->left = st.back();
                    st.pop_back();
                }
            }
            if(!st.empty()){
                st.back()->right = n;
            }
            st.push_back(n);
        }
        return st[0];
    }
};
