/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			vector<vector<int>> res;
			if(root == NULL) return res;
			TreeNode* p = root;
			queue<TreeNode*> que;
			que.push(p);
			bool left2right = true;
			while(!que.empty()){
				size_t si = que.size();
				vector<int> record(si);
				for(int i = 0; i < si; ++i){
					TreeNode* q = que.front();
					que.pop();
					if(q->left) que.push(q->left);
					if(q->right) que.push(q->right);
					int pos = left2right ? i : si - 1 - i;
					record[pos] = q->val;
				}
				res.emplace_back(record);
				left2right = !left2right;
			}
			return res;
		}
};
