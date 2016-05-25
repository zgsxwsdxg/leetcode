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
//版本二 ，一次forfor
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            const size_t N = matrix.size();
            for(size_t i = 0; i < N/2; ++i){
                for(size_t j = i; j < N - i - 1; j++){
                    int t = matrix[i][j];
                    matrix[i][j] = matrix[N - 1 - j][i];
                    matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
                    matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
                    matrix[j][N - 1 - i] = t;
                }
            }
        }
};
