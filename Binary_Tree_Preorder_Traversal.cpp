/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
// 版本一： 递归
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            _preorder(root);
            return res_;
        }
    private:
        void _preorder(TreeNode* root){
            if(root){
                res_.push_back(root->val);
                _preorder(root->left);
                _preorder(root->right);
            }
        }
    private:
        vector<int> res_;
};

//版本二 非递归
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> stk;
            TreeNode* p = root;
            while(p ||!stk.empty()){
                if(p){
                    res.push_back(p->val);
                    stk.push(p);
                    p = p->left;
                }
                else{
                    p = stk.top();
                    stk.pop();
                    p = p->right;
                }
            }
            return res;
        }
};
