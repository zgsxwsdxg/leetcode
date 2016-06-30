class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            N_ = grid.size();
            if(N_ <= 0 ) return 0;
            M_ = grid[0].size();
            int cnt = 0;
            for(int i = 0; i < N_; ++i){
                for(int j = 0; j < M_; ++j){
                    if(grid[i][j] == '1'){
                        ++cnt;
                        dfs(grid, i, j);
                    }
                }
            }
            return cnt;
        }
        void dfs(vector<vector<char>>& grid,int r, int c){
            grid[r][c] = '0';
            if(r > 0 && grid[r-1][c] == '1' ) dfs(grid, r-1, c);
            if(c < M_ - 1 && grid[r][c + 1] == '1') dfs(grid,r, c+ 1);
            if(r < N_ - 1 && grid[r + 1][c] == '1') dfs(grid, r+ 1, c);
            if(c > 0 && grid[r][c - 1] == '1') dfs(grid, r, c- 1);
        }
        void bfs(vector<vector<char>>& grid, int r, int c){
            queue<pair<int, int>> pos;
            pos.push(make_pair(r, c));
            grid[r][c] = '0';
            while (!pos.empty()){
                auto p = pos.front();
                pos.pop();
                grid[p.first][p.second] = '0';
                if (p.first > 0 && grid[p.first - 1][p.second] == '1'){
                    pos.push(make_pair(p.first - 1, p.second));
                    grid[p.first - 1][p.second] = '0';
                }
                if (p.second < M_ - 1 && grid[p.first][p.second + 1] == '1'){
                    pos.push(make_pair(p.first, p.second + 1));
                    grid[p.first][p.second + 1] = '0';
                }
                if (p.first < N_ - 1 && grid[p.first + 1][p.second] == '1'){
                    pos.push(make_pair(p.first + 1, p.second));
                    grid[p.first + 1][p.second] = '0';
                }
                if (p.second > 0 && grid[p.first][p.second - 1] == '1'){
                    pos.push(make_pair(p.first, p.second - 1));
                    grid[p.first][p.second - 1] = '0';
                }
            }
        }
        int M_;
        int N_;
};
