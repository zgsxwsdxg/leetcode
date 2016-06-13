// m1
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int rwb[3] ={0};
            for(auto n : nums){
                ++rwb[n];
            }
            for(size_t i = 0; i < rwb[0]; ++i){
                nums[i] = 0;
            }
            for(size_t i = rwb[0]; i < rwb[0] + rwb[1]; ++i){
                nums[i] = 1;
            }
            for(size_t i = rwb[0] + rwb[1]; i < nums.size(); ++i){
                nums[i] = 2;
            }
        }
};
