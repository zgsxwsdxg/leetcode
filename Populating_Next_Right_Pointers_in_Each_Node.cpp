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
            TreeLinkNode* p = root;
            while(p->left){
                TreeLinkNode* q = p->left;
                while(p->next){
                    p->left->next = p->right;
                    p->right->next = p->next->left;
                    p = p->next;
                }
                p->left->next = p->right;
                p->right->next =NULL;
                p = q;
            }
        }
};
