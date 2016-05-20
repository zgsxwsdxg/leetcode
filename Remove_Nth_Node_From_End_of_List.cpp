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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head == NULL || n <= 0 ) return head;
            ListNode hea(0);
            hea.next = head;
            ListNode* p = head;
            ListNode* q = &hea;
            while(n--){
                p = p->next;
            }
            while(p){
                p = p->next;
                q = q->next;
            }
            p = q->next;
            q->next = p->next;
            delete p;
            return hea.next;
        }
};
