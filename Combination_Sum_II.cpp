class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            target_ = target;
            com(candidates, 0 , 0);
            return res_;
        }
    private:
        void com(vector<int>& candidates,int pos ,int sum){
            if(sum > target_) return;
            if(sum == target_){
                res_.push_back(seq_);
            }
            else{
                for(int i = pos; i < candidates.size(); ){
                    seq_.push_back(candidates[i]);
                    com(candidates, i + 1, sum + candidates[i]);
                    int value = seq_[seq_.size() - 1];
                    seq_.pop_back();
                    // jump the same candidate
                    while(i < candidates.size() && candidates[i] == value){
                        ++i;
                    }
                }
            }
        }
    private:
        vector<vector<int>> res_;
        vector<int> seq_;
        int target_;
};
