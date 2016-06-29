/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode *> st;
            TreeNode* p = root;
            TreeNode* pre;
            while(p || !st.empty()){
                while(p){
                    st.push(p);
                    p = p->left;
                }
                p = st.top();
                if(p->right == NULL || p->right == pre){
                    res.push_back(p->val);
                    st.pop();
                    pre = p;
                    p = NULL;
                }
                else{
                    p = p->right;
                }
            }
            return res;
        }
};
