class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int l = nums.size();
            int s = 0;
            for(int i = 0; i < l; ++i){
                s += nums[i];
            }
            return (l + 1) * l / 2 - s;
        }
};
