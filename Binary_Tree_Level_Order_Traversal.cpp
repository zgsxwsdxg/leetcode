/*
 * Definition for a binary tree node.
 * struct TreeNode{
 * int val;
 * TreeNode * left;
 * TreeNode * right;
 * TreeNode(int x):val(x),left(NULL),right(NULL)
 * };
 */
class Solution {
	public:
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> res;
			vector<int> record;
			queue<TreeNode*> qu;
			if(root == NULL) return res;
			qu.push(root);
			int count = 1;
			int nextcount = 0;
			while(!qu.empty()){
				TreeNode* p = qu.front();
				qu.pop();
				TreeNode* node = p->left;
				if(node != NULL){
					qu.push(node);
					++nextcount;
				}
				node = p->right;
				if(node != NULL){
					qu.push(node);
					++nextcount;
				}
				record.push_back(p->val);
				--count;
				if(count == 0){
					res.push_back(record);
					record.clear();
					count = nextcount;
					nextcount = 0;
				}
			}
			return res;
		}
};
//great solution
class Solution {
	public:
		vector<vector<int>> levelOrder(TreeNode* root) {
			solve(root,0);
			return res_;
		}
	private:
		void solve(TreeNode* root,int level){
			if(root == NULL) return ;
			if(res_.size() > level){
				res_[level].push_back(root->val);
			}else{
				vector<int> a;
				a.push_back(root->val);
				res_.push_back(a);
			}
			solve(root->left, level + 1);
			solve(root->right, level + 1);
		}
	private:
		vector<vector<int>> res_;
};
