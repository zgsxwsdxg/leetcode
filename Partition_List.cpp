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
		ListNode* partition(ListNode* head, int x) {
			ListNode lesshead(0);
			ListNode gehead(0); // greatequal
			ListNode* lessrear = &lesshead;
			ListNode* gerear = &gehead;
			while(head){
				if(head->val < x){
					lessrear->next = head;
					lessrear = head;
				}else{
					gerear->next = head;
					gerear = head;
				}
				head = head->next;
			}
			gerear->next = NULL; // important 
			lessrear->next = gehead.next;
			return lesshead.next;
		}
};
