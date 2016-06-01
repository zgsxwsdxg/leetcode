/* struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
**/
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == NULL) {
                return 0;
            }
            int le = maxDepth(root->left);
            int ri = maxDepth(root->right);
            return std::max(le, ri) + 1;
        }
};
