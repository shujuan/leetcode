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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cur = 0;
        int carry = 0;
        ListNode* head = new ListNode(0), *tmp = head;
        while(l1!=NULL ||l2!=NULL||carry) {
            if(l1&&l2) {  
                cur = (l1->val + l2->val+ carry)%10;
                carry = (l1->val + l2->val+carry)/10;
                l1=l1->next;
                l2=l2->next;
            } else if(l1) {
                cur = (l1->val+carry)%10;
                carry = (l1->val +carry)/10;
                l1=l1->next;
            } else if(l2) {
                cur = (l2->val+carry)%10;
                carry = (l2->val +carry)/10;
                l2=l2->next;
            } else {
                cur = (carry)%10;
                carry = (carry)/10;
            }
           
            tmp->next = new ListNode(cur);
            tmp = tmp->next;
            
            
        }
        return head->next;
        
    }
};