class Solution {
    public:
        int trailingZeroes(int n) {
            int e = 5;
            int cnt = 0;
            while(n){
                n /= e;
                cnt += n;
            }
            return cnt;
        }
};
