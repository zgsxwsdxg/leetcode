class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> res(2, -1);
            int left = binsearch(nums, 0, nums.size() - 1, target - .5);
            if(nums[left] != target) return res;
            res[0] = left;
            int right = binsearch(nums,left, nums.size() - 1,target + .5);
            res[1] = right - 1;
            return res;
        }
    private:
        int binsearch(vector<int>& nums,int start,int end, double target){
            int left =start, right = end;
            while(left <= right){
                int mid = (left + right) / 2;
                if(target > nums[mid]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            return left;
        }
};
