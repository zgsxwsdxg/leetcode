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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return build(preorder,0,preorder.size() - 1, inorder, 0 , inorder.size() - 1);
        }
        TreeNode* build(vector<int>& preorder,int preleft,int preright,\
                vector<int>& inorder,int inleft, int inright){
            if(preleft > preright || inleft > inright) return NULL;
            TreeNode* root = new TreeNode(preorder[preleft]);
            auto it = find(inorder.begin() + inleft, inorder.begin() + inright + 1, preorder[preleft]) - inorder.begin();
            root->left = build(preorder, preleft + 1, it - inleft + preleft, inorder, inleft, it - 1);
            root->right = build(preorder, it + 1 - inright + preright, preright, inorder, it + 1, inright);
            return root;
        }
};
