class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> res(nums.size(),1);
      for(size_t i = 1; i < nums.size(); ++i){
        res[i] = res[i - 1] * nums[i - 1];
      }
      int r = 1;
      for(int i = nums.size() - 1; i >= 0; --i){
        res[i] *= r;
        r *= nums[i];
      }
      return res;
    }
};
