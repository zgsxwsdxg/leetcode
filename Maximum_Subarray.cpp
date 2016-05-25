class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int gsum = INT_MIN/2;
            int lsum = INT_MIN/2;
            for(auto num : nums){
                lsum = std::max(num, lsum + num);
                gsum = std::max(gsum, lsum);
            }
            return gsum;
        }
};
