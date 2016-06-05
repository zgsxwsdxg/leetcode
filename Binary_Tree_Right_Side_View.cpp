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
		vector<int> rightSideView(TreeNode* root) {
			vector<int> res;
			if(root == NULL) return res;
			queue<TreeNode*> que;
			que.push(root);
			int cnt = 1;
			int nextcnt = 0;
			while(!que.empty()){
				TreeNode* p = que.front();
				que.pop();
				--cnt;
				if(p->left){
					que.push(p->left);
					++nextcnt;
				}
				if(p->right){
					que.push(p->right);
					++nextcnt;
				}
				if(cnt == 0){
					res.push_back(p->val);
					cnt = nextcnt;
					nextcnt = 0;
				}
			}
			return res;
		}
};
