class Solution{
    public:
        pair<int, int> twoSum(vector<int>& nums, int target){
            int left = 0;
            int right = nums.size() - 1;
            while (left < right){
                if (nums[left] + nums[right] == target){
                    return make_pair(left, right);
                }
                else if (nums[left] + nums[right] > target){
                    --right;
                }
                else            {
                    ++left;
                }
            }
            return make_pair(-1, -1);
        }
};
