// p = { r1, r2, ..... rn }
// pi = p - ri;
// perm(p) = r1perm(p1) + r2perm(p2) .... + rnperm(pn)
class Solution {
	public:
		vector<vector<int>> permute(vector<int>& nums) {
			gen(nums, 0 );
			return res_;
		}
	private:
		void gen(vector<int>& nums,int pos){
			if(pos >= nums.size()){
				res_.push_back(nums);
			}
			else{
				for(int i = pos; i < nums.size(); ++i){
					std::swap(nums[i], nums[pos]);
					gen(nums, pos + 1);
					std::swap(nums[i], nums[pos]);
				}
			}
		}
	private:
		vector<vector<int>> res_;
};
