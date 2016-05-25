class Solution {
    public:
        double myPow(double x, int n) {
            if(n < 0) return power(1/x, -n);
            return power(x, n);
        }
        double power(double x, unsigned n) {
            if(n == 0) return 1.0;
            if(n == 1) return x;
            double p = power(x, n>>1);
            return p*p*(n&1 ? x : 1.0);
        }
};
