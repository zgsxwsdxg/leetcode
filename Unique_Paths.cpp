class Solution {
    public:
        int uniquePaths(int m, int n) {
            //f(x,y) = f(x-1,y) + f(x,y-1)
            int r = std::min(m, n);
            int c = std::max(m, n);
            vector<int> record(c, 1);
            for(int i = 1; i < r; ++i){
                record[i] *= 2;
                for(int j = i + 1; j < c; ++j){
                    record[j] += record[j - 1];
                }
            }
            return record[c - 1];
        }
};
