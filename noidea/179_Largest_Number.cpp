class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            std::sort(nums.begin(), nums.end(),[](int x, int y){
                    if(x == y) return false;
                    string xx = to_string(x);
                    string yy = to_string(y);
                    return (xx + yy) > (yy + xx);
                    });
            if(nums.size() > 0 && nums[0] == 0) return "0";
            string res = "";
            for(auto n : nums){
                res += to_string(n);
            }
            return res;
        }
};
