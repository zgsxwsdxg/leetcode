class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			/*
			//2Sum return the nums[i] + nums[j] == target
			std::sort(nums.begin(), nums.end());
			vector<int> res(2);
			int left = 0;
			int right = nums.size() - 1;
			while(left < right){
				if(nums[left] + nums[right] == target){
					res[0] = nums[left];
					res[1] = nums[right];
					return res;
				}
				else if(nums[left] + nums[right] > target){

					--right;
				}
				else{

					++left;
				}
			}
			return res;
			*/
			map<int,int> hash;
			vector<int> res(2);
			for(size_t i = 0; i < nums.size(); ++i){
				if(hash.find(target - nums[i]) != hash.end()){
					res[0] = hash[target - nums[i]];
					res[1] = i;
					return res;
				}
				hash[nums[i]] = i;
			}
			return res;
		}
};
