class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> res;
            vector<int> v;
            for(int i = 0 ; i < numRows; ++i){
                v.push_back(1);
                for(int j = i - 1 ; j > 0; --j){
                    v[j] += v[j - 1];
                }
                res.push_back(v);
            }
            return res;
        }
};
