class Solution {
    public:
        int nthUglyNumber(int n) {
            if(n <= 0) return -1;
            if(n == 1) return 1;
            int index2 = 0;
            int index3 = 0;
            int index5 = 0;
            vector<int> uns(n, 0);
            uns[0] = 1;
            for(int i = 1; i < n; ++i){
                int m = _min3(uns[index2] * 2, uns[index3] * 3, uns[index5] * 5);
                if(m == uns[index2] * 2) ++index2;
                if(m == uns[index3] * 3) ++index3;
                if(m == uns[index5] * 5) ++index5;
                uns[i] = m;
            }
            return uns[n - 1];
        }
    private:
        int _min3(int x, int y, int z){
            return std::min(std::min(x, y), z);
        }
};
