/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) { }
 ** };
 **/
class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			if(root == NULL) return true;
			return isSame(root->left, root->right);
		}
	private:
		bool isSame(TreeNode* left, TreeNode* right){
			if(left == NULL && right == NULL) return true;
			if(left && right){
				return left->val == right->val && isSame(left->left,right->right) && isSame(left->right, right->left);
			}
			return false;
		}
};
