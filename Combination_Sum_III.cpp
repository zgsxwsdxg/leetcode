class Solution {
    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            k_ = k;
            _com(1,n);
            return res_;
        }
    private:
        void _com(int pos, int sum){
            if(sum < 0 || record_.size() > k_) return ;
            if(sum == 0 && record_.size() == k_){
                res_.push_back(record_);
            }
            else{
                for(int i = pos; i < 10; ++i){
                    record_.push_back(i);
                    _com(i + 1, sum - i);
                    record_.pop_back();
                }
            }
        }
    private:
        vector<vector<int>> res_;
        vector<int> record_;
        int k_;
};
