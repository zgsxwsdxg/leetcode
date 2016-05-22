class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int profile = 0;
			for(size_t i = 1; i < prices.size(); ++i){
				profile += std::max(0, prices[i] - prices[i -1]);
			}
			return profile;
		}
};
