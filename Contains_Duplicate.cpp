// sort
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            std::sort(nums.begin(),nums.end());
            for(int i = 1; i < nums.size(); ++i){
                if(nums[i] == nums[i-1]) return true;
            }
            return false;
        }
};

// set
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            std::set<int> dup;
            for(int i = 0; i < nums.size(); ++i){
                if(dup.find(nums[i]) != dup.end()){
                    return true;
                }
                dup.insert(nums[i]);
            }
            return false;
        }
};
