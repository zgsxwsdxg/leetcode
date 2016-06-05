class Solution {
	public:
		void rotate(vector<int>& nums, int k) {
			int n = nums.size();
			k %= n;
			if(k == 0) return ;
			_t(nums, 0, n - 1);
			_t(nums, 0, k - 1);
			_t(nums, k, n - 1);
		}
		void _t(vector<int>& nums, int start, int end){
			while(start < end){
				std::swap(nums[start++], nums[end--]);
			}
		}
};
