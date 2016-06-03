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
		bool hasPathSum(TreeNode* root, int sum) {
			if(root == NULL) return false;
			if(root->left == NULL && root->right == NULL && root->val == sum){
				return true;
			}
			sum -= root->val;
			bool b =hasPathSum(root->left, sum);
			return b?true:hasPathSum(root->right,sum);
		}
};
// better 
class Solution {
	public:
		bool hasPathSum(TreeNode* root, int sum) {
			if(root == NULL) return false;
			if(root->left == NULL && root->right == NULL){
				return root->val == sum;
			}
			sum -= root->val;
			return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
		}
};
