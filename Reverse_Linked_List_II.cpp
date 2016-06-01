/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/
class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            ListNode h(0);
            ListNode* p = &h;
            h.next = head;
            n=n - m + 1;
            while(--m){
                p = p->next;
            }
            ListNode* r = p->next;
            ListNode* q = p->next;
            while(n--){
                ListNode* t = q->next;
                q->next = p->next;
                p->next = q;
                q = t;
            }
            r->next = q;
            return h.next;
        }
};
