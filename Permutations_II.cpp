class Solution {
	public:
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			//std::sort(nums.begin(), nums.end());
			gen(nums, 0);
			return res_;
		}
	private:
		void gen(vector<int>& nums, int pos){
			if(pos >= nums.size()){
				res_.push_back(nums);
			}
			else{
				for(int i = pos; i < nums.size(); ++i){
					if(!isSwap(nums, pos, i)) continue;
					std::swap(nums[i], nums[pos]);
					gen(nums, pos + 1);
					std::swap(nums[i], nums[pos]);
				}
			}
		}
		bool isSwap(vector<int>& nums, int pos,int i){
			while( pos < i && nums[pos] != nums[i]){
				++pos;
			}
			return pos == i;
		}
	private:
		vector<vector<int>> res_;
};
