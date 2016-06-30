class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            N_ = board.size();
            if (N_ <= 0) return false;
            M_ = board[0].size();
            for (size_t i = 0; i < N_; ++i){
                for (size_t j = 0; j < M_; ++j){
                    int res = dfs(board, i, j, word, 0);
                    if (res) return true;
                }
            }
            return false;
        }
        bool dfs(vector<vector<char>>& board, int r, int c, string& word, int pos){
            if (board[r][c] != word[pos]) return false;
            if (pos >= word.size() - 1) return true;
            char t = board[r][c];
            board[r][c] = ' ';
            bool res = false;
            if (r > 0) res = dfs(board, r - 1, c, word, pos + 1);
            if (!res && c < M_ - 1) res = dfs(board, r, c + 1, word, pos + 1);
            if (!res && r < N_ - 1) res = dfs(board,r + 1, c, word, pos + 1);
            if (!res && c > 0) res = dfs(board, r, c - 1, word, pos + 1);
            board[r][c] = t;
            return res;
        }
    private:
        int N_;
        int M_;
};
