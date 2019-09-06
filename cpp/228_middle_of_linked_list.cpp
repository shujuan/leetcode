/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode * middleNode(ListNode * head) {
        // write your code here
        auto fast = head, slow = head;
        while(fast&& fast->next) {
            
            fast = fast->next->next;
            if(!fast) break;
            slow = slow->next;
        }
        
        return slow;
    }
};
