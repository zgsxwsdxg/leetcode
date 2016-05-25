class Solution {
    public:
        int jump(vector<int>& nums) {
            size_t pos = 0;
            size_t step = 0;
            size_t nextmaxpos = pos;
            for(size_t i = 0; i < nums.size(); ++i){
                if(pos < i){
                    ++step;
                    pos = nextmaxpos;
                }
                nextmaxpos = std::max(nextmaxpos, nums[i] + i);
            }
            return step;
        }
};
