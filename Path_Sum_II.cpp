/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
// 前序遍历，使用record记录路径
class Solution {
	public:
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			_sub(root, sum);
			return res_;
		}
	private:
		void _sub(TreeNode* root, int sum){
			if(root == NULL) return ;
			record_.push_back(root->val);
			if(root->left == NULL && root->right == NULL){
				if(root->val == sum){
					res_.push_back(record_);
				}
				record_.pop_back();
				return;
			}
			sum -= root->val;
			_sub(root->left, sum);
			_sub(root->right, sum);
			record_.pop_back();
		}
	private:
		vector<vector<int>> res_;
		vector<int> record_;
};
class Solution {
	public:
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			sub(root,sum);
			return vvi;
		}
	private:
		void sub(TreeNode* root, int sum){
			if(root==NULL)return ;
			if(root->left==NULL&&root->right==NULL&&root->val==sum){
				vi.push_back(root->val);
				vvi.push_back(vi);
				vi.pop_back();
				return ;
			}
			vi.push_back(root->val);
			sub(root->left,sum-root->val);
			sub(root->right,sum-root->val);
			vi.pop_back();
		}
	private:
		vector<vector<int>> vvi;
		vector<int> vi;
};
