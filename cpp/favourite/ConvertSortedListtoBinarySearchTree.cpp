/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        ListNode *fast = head, *slow = head, *last = slow;
        while(fast && fast->next) {
            last = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* res = new TreeNode(slow->val);
       
        fast = slow->next;
        last->next = NULL;
        if(head!=slow) res->left = sortedListToBST(head);
        res->right = sortedListToBST(fast);
        
        
        return res;
       
        
        
        
    }
};