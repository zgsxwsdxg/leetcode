class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n = word1.size();
            int m = word2.size();
            vector<vector<int>> records(n + 1, vector<int>(m + 1));
            for(int i= 0; i < n + 1; ++i){
                records[i][0] = i;
            }
            for(int i= 0; i < m + 1; ++i){
                records[0][i] = i;
            }
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    records[i + 1][j + 1] = _3min(records[i][j] + static_cast<int>(word1[i] != word2[j]), records[i + 1][j] + 1, records[i][j + 1] + 1);
                }
            }
            return records[n][m];
        }
    private:
        inline int _3min(int x, int y, int z){
            return std::min(std::min(x, y), z);
        }
};
