class Solution{
public:
	int rob(vector<int>& nums){
		int f_2 = 0;
		int f_1 = 0;
		int f = 0;
		for(size_t i = 0; i < nums.size(); ++i){
			f = std::max(f_2 + nums[i], f_1);
			f_2 = f_1;
			f_1 = f;
		}
		return f;
	}
}
