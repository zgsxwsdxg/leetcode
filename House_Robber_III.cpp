/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
class Solution {
    public:
        int rob(TreeNode* root) {
            int leftrob , rightrob;
            return _rob(root,leftrob,rightrob);
        }
        int _rob(TreeNode* root, int& leftrob, int& rightrob){
            if(root == NULL){
                leftrob = 0;
                rightrob = 0;
                return 0;
            }
            int ll, lr, rl ,rr;
            leftrob = _rob(root->left, ll, lr);
            rightrob = _rob(root->right, rl ,rr);
            return max(root->val + ll + lr + rl + rr, leftrob + rightrob);
        }
};
