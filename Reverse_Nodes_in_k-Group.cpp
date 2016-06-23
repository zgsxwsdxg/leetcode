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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(head == NULL || k <= 1) return  head;
            ListNode h(0);
            ListNode* rear = &h;
            ListNode* p = head,* q = NULL,* s = NULL,*t = NULL, * u = NULL;
            while(1){
                int c = 1;
                q = p;
                while(q && c < k){
                    q = q->next;
                    ++c;
                }
                if(q == NULL){
                    rear->next = p;
                    break;
                }
                else{
                    t = p;
                    u = q->next;
                    rear->next = NULL;
                    while(p != q){
                        s = p->next;
                        p->next = rear->next;
                        rear->next = p;
                        p = s;
                    }
                    q->next = rear->next;
                    rear->next = q;
                    rear = t;
                }
                p = u;
            }
            return h.next;
        }
};
