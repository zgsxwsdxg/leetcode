/**
 ** Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 **/
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int f = 0;
            ListNode head(0);
            ListNode * rear = &head;
            while(l1 && l2){
                int v = l1->val + l2->val + f;
                f = v / 10;
                v %= 10;
                ListNode* t = new ListNode(v);
                rear->next = t;
                rear = rear->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            while(l1){
                int v = l1->val  + f;
                f = v / 10;
                v %= 10;
                ListNode* t = new ListNode(v);
                rear->next = t;
                rear = rear->next;
                l1 = l1->next;
            }
            while(l2){
                int v = l2->val + f;
                f = v / 10;
                v %= 10;
                ListNode* t = new ListNode(v);
                rear->next = t;
                rear = rear->next;
                l2 = l2->next;
            }
            if(f){
                ListNode* t = new ListNode(f);
                rear->next = t;
                rear = rear->next;
            }
            rear->next = NULL;
            return head.next;


        }

};
