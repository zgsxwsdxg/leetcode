class Solution {
    public:
        bool canJump(vector<int>& nums) {
            size_t maxpos = 0;
            for(size_t i = 0; i < nums.size(); ++i){
                if(maxpos < i){
                    return false;
                }
                maxpos = std::max(maxpos, i + nums[i]);
            }
            return true;
        }
};
