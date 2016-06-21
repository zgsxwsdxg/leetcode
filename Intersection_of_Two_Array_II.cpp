// m1
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            std::sort(nums1.begin(),nums1.end());
            std::sort(nums2.begin(), nums2.end());
            int n = nums1.size(), m = nums2.size();
            int i = 0, j = 0;
            vector<int> res;
            while(i < n && j < m){
                if(nums1[i] == nums2[j]){
                    res.push_back(nums1[i]);
                    ++i, ++j;
                }
                else if(nums1[i] > nums2[j] ){
                    ++j;
                }
                else{
                    ++i;
                }
            }
            return res;
        }
};

// m2
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> have;
            for(auto n : nums1){
                ++have[n];
            }
            vector<int> res ;
            for(auto n : nums2){
                if( have.find(n) != have.end() && have[n] > 0){
                    res.push_back(n);
                    --have[n];
                }
            }
            return res;
        }
};
