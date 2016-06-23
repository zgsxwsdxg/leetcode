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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        }
    private:
        TreeNode* build(vector<int>& inorder, int inleft, int inright, vector<int>& postorder, int postleft, int postright){
            if(inleft > inright || postleft > postright) return NULL;
            int v = postorder[postright];
            TreeNode* root = new TreeNode(v);
            auto it = find(inorder.begin() + inleft, inorder.begin() + inright + 1, v) - inorder.begin();
            root->left = build(inorder, inleft, it - 1, postorder, postleft, it - 1 - inleft + postleft);
            root->right = build(inorder, it + 1, inright, postorder, it - inright + postright , postright - 1);
            return root;
        }
};
