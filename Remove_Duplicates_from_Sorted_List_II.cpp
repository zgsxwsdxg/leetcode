/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 **/
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode h(INT_MIN);
            ListNode* rear = &h;
            ListNode *p = head;
            ListNode *q = NULL;
            while(p){
                q = p->next;
                while(q && q->val == p->val){
                    q = q->next;
                }
                if(p->next == q){
                    rear->next = p;
                    rear = p;
                }
                p = q;
            }
            rear->next = NULL;
            return h.next;
        }

};
