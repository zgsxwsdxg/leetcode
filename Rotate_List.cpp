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
		ListNode* rotateRight(ListNode* head, int k) {
			if(head == NULL) return NULL;
			int len = _len(head);
			k %= len;
			if(k == 0) return head;
			ListNode* p = head;
			ListNode* q = head;
			while(k--){
				p = p->next;
			}
			while(p->next){
				p = p->next;
				q = q->next;
			}
			p->next = head;
			head = q->next;
			q->next = NULL;
			return head;
		}
		int _len(ListNode* head){
			int l = 0;
			while(head){
				++l;
				head= head->next;
			}
			return l;
		}
};
