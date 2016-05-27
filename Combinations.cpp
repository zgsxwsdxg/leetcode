class Solution {
	public:
		vector<vector<int>> combine(int n, int k) {
			n_ = n;
			k_ = k;
			com(1);
			return res_;
		}
	private:
		void com(int pos){
			if(record_.size() > k_) return ;
			if(record_.size() == k_){
				res_.push_back(record_);
			}else{
				for(int i = pos; i <= n_; ++i){
					record_.push_back(i);
					com(i + 1);
					record_.pop_back();
				}
			}
		}
	private:
		vector<vector<int>> res_;
		vector<int> record_;
		int k_;
		int n_;
};
