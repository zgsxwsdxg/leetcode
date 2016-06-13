class Solution {
    public:
        int mySqrt(int x) {
            if(x <= 0) return 0;
            int x1 = x / 2 + 1;
            while(x1  > x / x1){
                x1 = (x1 + x / x1) / 2;
            }
            return x1;
        }
};
