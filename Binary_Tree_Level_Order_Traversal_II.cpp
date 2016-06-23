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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> res;
            if(root == NULL) return res;
            queue<TreeNode*> que;
            que.push(root);
            int cur = 1;
            int next = 0;
            vector<int> record;
            while(!que.empty()){
                TreeNode* p = que.front();
                record.push_back(p->val);
                que.pop();
                --cur;
                if(p->left){
                    ++next;
                    que.push(p->left);
                }
                if(p->right){
                    ++next;
                    que.push(p->right);
                }
                if(cur == 0){
                    res.push_back(record);
                    record.clear();
                    cur = next;
                    next = 0;
                }
            }
            reverse(res.begin(), res.end());
            return res;
        }
};
