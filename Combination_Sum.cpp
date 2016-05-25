class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            //vector<vector<int>> res;
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
                for(int i = pos; i < candidates.size(); ++i){
                    seq_.push_back(candidates[i]);
                    com(candidates, i, sum + candidates[i]);
                    seq_.pop_back();
                }
            }
        }
    private:
        vector<vector<int>> res_;
        vector<int> seq_;
        int target_;
};
