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
    ListNode* swapPairs(ListNode* head) {
        ListNode h(0);
        ListNode* rear = &h;
        ListNode* p = head;
        while(p){
            if(p->next){
                ListNode* q = p->next->next;
                rear->next = p->next;
                p->next->next = p;
                rear = p;
                p = q;
            }
            else{
                rear->next = p;
                rear = p;
                p = p->next;
            }
        }
        rear->next = NULL;
        return h.next;
    }
};
