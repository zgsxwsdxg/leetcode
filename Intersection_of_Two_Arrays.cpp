class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            std::sort(nums1.begin(), nums1.end());
            std::sort(nums2.begin(), nums2.end());
            vector<int> res;
            int pre = INT_MAX;
            size_t i = 0, j = 0;
            while(i < nums1.size() && j < nums2.size()){
                if(nums1[i] == nums2[j]){
                    if(pre != nums1[i]){
                        res.push_back(nums1[i]);
                        pre = nums1[i];
                    }
                    ++i,++j;
                }
                else if(nums1[i] > nums2[j]){
                    ++j;
                }
                else{
                    ++i;
                }
            }
            return res;
        }
};

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> res;
            map<int,int> mii;
            for(auto i : nums1){
                mii[i] = 1;
            }
            for(auto i : nums2){
                if(mii[i] == 1){
                    res.push_back(i);
                    ++mii[i];
                }
            }
            return res;
        }
};
