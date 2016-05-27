class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			int f = 1;
			vector<int> res;
			for(int i = digits.size() - 1; i >= 0; --i){
				int t = f + digits[i];
				f = t / 10;
				t = t % 10;
				res.push_back(t);
			}
			if(f){
				res.push_back(f);
			}
			std::reverse(res.begin(), res.end());
			return res;
		}
};
