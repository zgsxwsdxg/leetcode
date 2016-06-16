class Solution {
    public:
        int countNumbersWithUniqueDigits(int n) {
            if(n <= 0) return 1;
            n = std::min(10, n);
            int res = 10;
            int pre = 9;
            for(int i = 2; i <= n; ++i){
                pre *= (11 - i);
                res += pre;
            }
            return res;
        }
};
