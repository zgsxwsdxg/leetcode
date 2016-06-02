class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int me = INT_MIN;
            int cnt = 1;
            for(size_t i = 0; i < nums.size(); ++i){
                if(me != nums[i]){
                    --cnt;
                }else{
                    ++cnt;
                }
                if(cnt == 0){
                    me = nums[i];
                    cnt = 1;
                }
            }
            return me;
        }
};
