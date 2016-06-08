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
        ListNode *detectCycle(ListNode *head) {
            ListNode * p = head;
            ListNode * q = head;
            if(!hasCycle(p,q)){
                return NULL;
            }
            else{
                p = p->next;
                int len1 = len(head, q);
                int len2 = len(p, q);
                if(len1 < len2)
                    std::swap(head,p);
                int n = std::abs(len1 - len2);
                while(n--){
                    head = head->next;
                }
                while(head != p){
                    head = head->next;
                    p = p->next;
                }
                return head;
            }
        }
    private:
        bool hasCycle(ListNode* &p,ListNode* &q){
            while(p){
                p = p->next;
                q = q->next;
                if(p) p = p->next;
                else return false;
                if(p == q) return true;
            }
            return false;
        }
        int len(ListNode* st,ListNode* en){
            int len = 1;
            while(st != en){
                ++len;
                st = st->next;
            }
            return len;
        }
};
