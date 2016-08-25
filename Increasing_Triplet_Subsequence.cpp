// LIS
class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            if(nums.size() < 3) return false;
            vector<int> dp(nums.size(), 0);
            for(size_t i = 0; i < nums.size(); ++i){
                int m = 1;
                for(size_t j = 0; j < i ; ++j){
                    if(nums[j] < nums[i]){
                        m = std::max(m , dp[j] + 1);
                    }
                }
                dp[i] = m;
                if(m >= 3) return true;
            }
            //return *std::max_element(dp.begin(), dp.end()) >= 3;
            return false;
        }
};

class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            if(nums.size() < 3 ) return false;
            vector<int> leftmin(nums.size());
            vector<int> rightmax(nums.size());
            int leftminval = INT_MAX;
            for(size_t i = 0; i < nums.size(); ++i){
                leftminval = std::min(leftminval, nums[i]);
                leftmin[i] = leftminval;
            }
            int rightmaxval = INT_MIN;
            for(int i = nums.size() - 1; i >= 0; --i){
                rightmaxval = std::max(rightmaxval, nums[i]);
                rightmax[i] = rightmaxval;
            }
            for(size_t i = 1; i < nums.size() - 1; ++i ){
                if(nums[i] > leftmin[i] && nums[i] < rightmax[i]){
                    return true;
                }
            }
            return false;
        }
};

// the best solution
//  https://discuss.leetcode.com/topic/37281/clean-and-short-with-comments-c/12
