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
        ListNode* reverseList(ListNode* head) {
            ListNode h(0);
            h.next = NULL;
            //ListNode* rear = &h;
            ListNode* q = head;
            while(q){
                ListNode* p = q->next;
                q->next = h.next;
                h.next = q;
                q = p;
            }
            return h.next;
        }
};
