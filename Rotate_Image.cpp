// 版本一：容易理解但是两次forfor
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int N = matrix.size();
            //转置
            for(int i = 0; i < N; ++i){
                for(int j = i + 1; j < N; j++){
                    std::swap(matrix[i][j], matrix[j][i]);
                }
            }
            //翻转
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N/2; j++){
                    std::swap(matrix[i][j], matrix[i][N - j - 1]);
                }
            }
        }
};
