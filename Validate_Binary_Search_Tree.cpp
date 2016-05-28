struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {
	}
};
//版本一：递归
class Solution {
	public:
		bool isValidBST(TreeNode* root) {
			if(root == NULL) return true;
			bool bleft = isValidBST(root->left);
			bool flag = pre < root->val;
			pre = root->val;
			return bleft && flag && isValidBST(root->right);
		}
	private:
		double pre = INT_MIN - 1.0;
};
// 版本二 ，非递归中序遍历
class Solution {
	public:
		bool isValidBST(TreeNode* root) {
			stack<TreeNode*> st;
			TreeNode* p = root;
			while(p || !st.empty()){
				if(p){
					st.push(p);
					p = p->left;
				}else{
					p = st.top();
					st.pop();
					if(pre >= p->val) return false;
					pre = p->val;
					p = p->right;
				}
			}
			return true;
		}
	private:
		double pre = INT_MIN - 1.0;
};
