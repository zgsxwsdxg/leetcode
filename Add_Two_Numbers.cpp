/**
 ** Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 **/
// 版本1 ，开辟新空间
// 注意事项：需要判断最后家和是否大于10，如果大于，则需要再次new Node
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
//版本2 ，使用l1 l2 内存空间
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int f = 0;
            ListNode head(0);
//            head.next = l1;
            ListNode* rear = &head;
            ListNode* p1 = l2;
            while (l1 && l2){
                int v = f + l1->val + l2->val;
                f = v / 10;
                v %= 10;
                l1->val = v;
                rear->next = l1;
                rear = l1;
                l1 = l1->next;
                l2 = l2->next;
            }
            ListNode* p2 = l2;//记录可能用到l2 中的开始位置
            while (l1 && f){
                int v = f + l1->val;
                f = v / 10;
                v %= 10;
                l1->val = v;
                rear->next = l1;
                rear = l1;
                l1 = l1->next;
            }
            if(l2) rear->next = l2;//判断l2是否还有数据
            while (l2 && f){
                int v = f + l2->val;
                f = v / 10;
                v %= 10;
                l2->val = v;
                rear->next = l2;
                rear = l2;
                l2 = l2->next;
            }
            if (f){
                ListNode * t = new ListNode(f);
                rear->next =  t;
                rear = t;
            }
            //释放l2中的资源
            while (p1 != p2){
                ListNode* t = p1->next;
                delete p1;
                p1 = t;
            }
            return head.next;
        }
};
