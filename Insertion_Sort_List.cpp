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
        ListNode* insertionSortList(ListNode* head) {
            ListNode h(INT_MIN);
            ListNode* hp = &h;
            ListNode* p = head;
            while(p){
                ListNode* q = p->next;
                while(hp->next && hp->next->val < p ->val){
                    hp = hp->next;
                }
                p->next = hp->next;
                hp->next = p;
                hp = &h;
                p = q;
            }
            return h.next;
        }

};
