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
        ListNode* oddEvenList(ListNode* head) {
            ListNode ohead(0);
            ListNode ehead(0);
            ListNode* orear = &ohead;
            ListNode* erear = &ehead;
            bool flag = true;
            while(head){
                if(flag){
                    orear->next = head;
                    orear = head;
                    flag = false;
                }
                else{
                    erear->next = head;
                    erear = head;
                    flag = true;
                }
                head = head->next;
            }
            erear->next = NULL;
            orear->next = ehead.next;
            return ohead.next;
        }
};
