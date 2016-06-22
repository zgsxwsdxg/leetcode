class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int res = 0;
            for(int i = 0; i < 32; ++i){
                int tmp = 0;
                for(auto n : nums){
                    tmp += ((n >> i) & 1);
                }
                res += (tmp%3) *(1 << i);
            }
            return res;
        }
};
