/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 **/
class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            RandomListNode* p = head;
            while(p){
                RandomListNode *q = p->next;
                RandomListNode* n = new RandomListNode(p->label);
                p->next = n;
                n->next = q;
                p = q;
            }
            RandomListNode h(0);
            RandomListNode *rear = &h;
            p = head;
            while(p){
                RandomListNode* q = p->next->next;
                p->next->random = p->random ? p->random->next : NULL;
                p = q;
            }
            p = head;
            while(p){
                RandomListNode* q = p->next->next;
                rear->next = p->next;
                rear= rear->next;
                p->next = q;
                p = q;
            }
            rear->next = NULL;
            return h.next;
        }
};
