class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			// nums.push_back(INT_MIN);//增加哨兵
			com(nums,0);
			// nums.pop_back();
			return res;
		}
	private:
		void com(vector<int>& nums, int pos){
			res.push_back(record);
			for(size_t i = pos; i < nums.size()/*nums.size() - 1//增加了哨兵 */; ){
				record.push_back(nums[i]);
				com(nums, i + 1);
				int r = record.back();
				while(i < nums.size() && nums[i] == r) ++i;
				//while( nums[i] == r) ++i; 哨兵在，所以不用判断最后一个数
				record.pop_back();
			}
		}
	private:
		vector<vector<int>> res;
		vector<int> record;
};
