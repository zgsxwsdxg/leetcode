/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {
 *     };
 */
//版本一，递归
class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			inorder(root);
			return res;
		}
	private:
		void inorder(TreeNode* root){
			if(root){
				inorder(root->left);
				res.push_back(root->val);
				inorder(root->right);
			}
		}
	private:
		vector<int> res;
};
//版本二，循环+栈
class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> res;
			TreeNode* p = root;
			stack<TreeNode*> st;
			while(p || !st.empty()){
				if(p){
					st.push(p);
					p = p->left;
				}
				else{
					p = st.top();
					st.pop();
					res.push_back(p->val);
					p = p->right;
				}
			}
			return res;
		}
	private:
};
