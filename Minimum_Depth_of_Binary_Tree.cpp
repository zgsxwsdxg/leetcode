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
		int minDepth(TreeNode* root) {
			if(root == NULL) return 0;
			if(root->left == NULL && root->right == NULL) return 1;
			int dl = INT_MAX;
			int dr = INT_MAX;
			if(root->left){
				dl = minDepth(root->left);
			}
			if(root->right){
				dr = minDepth(root->right);
			}
			return std::min(dl, dr) + 1;
		}
};
