class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int N = triangle.size();
            if(N <= 0) return 0;
            vector<int> record(N,0);
            record[0] = triangle[0][0];
            for(int i = 1; i < N; ++i){
                record[i] = record[i - 1] + triangle[i][i];
                for(int j = i - 1; j > 0 ; --j ){
                    record[j] = std::min(record[j], record[j - 1]) + triangle[i][j];
                }
                record[0] +=triangle[i][0];
            }
            int res = INT_MAX;
            for(int i = 0; i < N; ++i){
                res = std::min(res, record[i]);
            }
            return res;
        }
};
