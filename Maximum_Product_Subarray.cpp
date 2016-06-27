class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int posmax = 1;
            int negmax = 1;
            int res = INT_MIN;
            for(auto n : nums){
                int t1 = _3min(posmax*n, negmax*n, n);
                int t2 = _3max(posmax*n, negmax*n, n);
                res = std::max(res, t2);
                posmax = t2;
                negmax = t1;
            }
            return res;
        }
        int _3min(int x, int y, int z){
            return std::min(x, std::min(y, z));
        }
        int _3max(int x, int y, int z){
            return std::max(x, std::max(y, z));
        }

};
