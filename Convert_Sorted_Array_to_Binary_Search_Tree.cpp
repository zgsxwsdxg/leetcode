/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
class Solution {
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			return _2BST(nums, 0 , nums.size() - 1);
		}
	private:
		TreeNode* _2BST(vector<int>& nums, int start, int end){
			if(start <= end){
				int mid = (start + end) /2 + (start + end)%2;
				TreeNode* head = new TreeNode(nums[mid]);
				head->left = _2BST(nums,start, mid - 1);
				head->right = _2BST(nums, mid + 1, end);
				return head;
			}
			return NULL;
		}
};
