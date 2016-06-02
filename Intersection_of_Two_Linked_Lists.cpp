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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int lenA = len(headA);
            int lenB = len(headB);
            ListNode* longlist = headA;
            ListNode* shortlist = headB;
            if(lenA < lenB){
                std::swap(longlist, shortlist);
            }
            int dis = std::abs(lenA - lenB);
            while(dis--){
                longlist = longlist->next;
            }
            while(longlist != shortlist){
                longlist = longlist->next;
                shortlist = shortlist->next;
            }
            return longlist;
        }
    private:
        int len(ListNode* head){
            int n = 0;
            while(head){
                ++n;
                head = head->next;
            }
            return n;
        }
};
