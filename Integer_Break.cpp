class Solution {
    public:
        int integerBreak(int n) {
            if(n < 2) return -1;
            if(n == 2) return 1;
            if(n == 3) return 2;
            if(n == 4) return 4;
            if(n == 5) return 6;
            if(n == 6) return 9;
            return 3*integerBreak(n - 3);
        }
};

class Solution {
    public:
        int integerBreak(int n) {
            if(n < 2) return -1;
            int f[] = {1, 1, 1, 2, 4, 6, 9};
            if(n <= 6) return f[n];
            int x = n / 3;
            int y = n % 3;
            int res = 0;
            //res = std::max((int)pow(3, x) * f[y], (int)(pow(3, x-1)) * f[y + 3]);
            if(y != 0){
                y += 3;
                --x;
            }
            res = pow(3, x) * f[y];
            return res;
        }
}
