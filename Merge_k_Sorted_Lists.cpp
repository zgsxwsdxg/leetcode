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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() <= 0) return NULL;
        return merge(lists, 0, lists.size() -1);
    }
private:
    ListNode* merge(vector<ListNode*>& lists,int start, int end){
        if(start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode* left = merge(lists, start, mid);
        ListNode* right = merge(lists, mid + 1, end);
        return merge(left, right);
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode head(0);
        ListNode* rear = & head;
        while(list1 && list2){
            if(list1->val < list2->val){
                rear->next = list1;
                rear = list1;
                list1 = list1->next;
            }
            else{
                rear->next = list2;
                rear = list2;
                list2 = list2->next;
            }
        }
        if(list1){
            rear->next = list1;
        }
        if(list2){
            rear->next = list2;
        }
        return head.next;
    }
};


struct cmp{
    bool operator()(ListNode* n1, ListNode* n2){
        return n1->val > n2->val;
    }
};
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.size() <= 0) return NULL;
            ListNode head(0);
            ListNode* rear = &head;
            std::priority_queue<ListNode*, vector<ListNode*>, cmp> heap;// 小顶堆
            for(int i = 0 ;i < lists.size(); ++i){
                if(lists[i] != NULL)
                    heap.push(lists[i]);
            }
            while(!heap.empty()){
                ListNode* node = heap.top();
                heap.pop();
                if(NULL != node->next) heap.push(node->next);
                rear->next = node;
                rear = node;
            }
            rear->next = NULL;
            return head.next;
        }
};
