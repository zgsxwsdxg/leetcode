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
            ListNode * rear = &h;
            ListNode *q,*p;
            p = head;
            while(p){
                q = p->next;
                if(rear->val != p->val){
                    rear->next = p;
                    rear = p;
                }
                p = q;
            }
            rear->next = NULL;
            return h.next;
        }

};
