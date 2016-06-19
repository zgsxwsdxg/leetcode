class Solution {
	public:
		int firstMissingPositive(vector<int>& nums) {
			for(size_t i = 0; i < nums.size(); ++i){
				while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]){
					std::swap(nums[nums[i] - 1], nums[i]);
				}
			}
			for(size_t i = 0; i < nums.size(); ++i){
				if(nums[i] != i+1){
					return i + 1;
				}
			}
			return nums.size() + 1;
		}
};
