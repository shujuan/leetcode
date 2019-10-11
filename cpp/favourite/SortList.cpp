/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head ||!head->next) return head;
        ListNode* slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    
    }
    
    ListNode* merge(ListNode* l1, ListNode*l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;
        
        while(l1 || l2) {
            if(l1 && l2){
                if(l1->val < l2->val) {
                    dummy->next = l1;
                    l1 = l1->next;
                    
                } else {
                    dummy->next = l2;
                    l2 = l2->next;
                }
                
               

            } else if (l1) {
                dummy->next = l1;
                l1 = l1->next;
            } else {
                dummy->next = l2;
                l2 = l2->next;
            }
            
            dummy = dummy->next;
        }
        
        return tmp->next;
            
    }
    
};