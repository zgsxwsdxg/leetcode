class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int pre = INT_MIN;
            int c = 0;
            int res= -1;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] == pre){
                    ++c;
                }else{
                    for(int j = 0; j < std::min(2,c); ++j){
                        nums[++res] = pre;
                    }
                    pre = nums[i];
                    c = 1;
                }
            }
            if(c != 0){
                for(int j = 0; j < std::min(2,c); ++j){
                    nums[++res] = pre;
                }
            }
            return (res+1);
        }

};


class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int pre = INT_MIN;
            int c = 0;
            int res= -1;
            nums.push_back(INT_MAX);//增加哨兵
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] == pre){
                    ++c;
                }else{
                    for(int j = 0; j < std::min(2,c); ++j){
                        nums[++res] = pre;
                    }
                    pre = nums[i];
                    c = 1;
                }
            }
            nums.pop_back();//删除哨兵
            return (res+1);
        }

};
