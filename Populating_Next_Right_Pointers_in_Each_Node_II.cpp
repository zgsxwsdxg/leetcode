/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 **/
class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if(root == NULL) return ;
            TreeLinkNode * p = root;
            TreeLinkNode * q = NULL;
            while(p){
                TreeLinkNode h(0);
                TreeLinkNode* rear  = &h;
                while(p){
                    if(p->left){
                        rear->next = p->left;
                        rear = rear->next;
                    }
                    if(p->right){
                        rear->next = p->right;
                        rear = rear->next;
                    }
                    p = p->next;
                }
                rear->next = NULL;
                p = h.next;
            }
        }

};
