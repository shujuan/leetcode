/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto tmp = head;
        Node* cpTmp;
        if(!head) return nullptr;
        while(tmp) {
            cpTmp = new Node(tmp->val, NULL, NULL);
            Node* origNext = tmp->next;
            tmp->next = cpTmp;
            cpTmp->next = origNext;
            tmp = origNext;
        }
        
        tmp = head;
        auto cpHead = head->next;
        while(tmp) {
            cpTmp= tmp->next;
            if(tmp->random)cpTmp->random = tmp->random->next;
            
            
            tmp= cpTmp->next;
        }
        
        tmp = head;
        while(tmp) {
            cpTmp = tmp->next;
            tmp->next = cpTmp->next;
            if(tmp->next) cpTmp->next = tmp->next->next;
            tmp = tmp->next;
        }
        
        
        
        return cpHead;
        
        
    }
};