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
        ListNode* removeElements(ListNode* head, int val) {
            ListNode newhead(0);
            ListNode* rear = &newhead;
            while(head){
                if(head->val != val){
                    rear->next = head;
                    rear = head;
                }
                head = head->next;
            }
            rear->next = NULL;
            return newhead.next;
        }

};
