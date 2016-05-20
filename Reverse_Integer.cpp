class Solution {
    public:
        int reverse(int x) {
            double r = 0;
            while(x){
                r = r * 10 + x % 10;
                x /= 10;

            }
            if(r > INT_MAX || r < INT_MIN) r = 0;
            return static_cast<int>(r);

        }
        int reverse2(int x) {
            int r = 0;
            while(x){
                if(r > INT_MAX / 10 || r > INT_MIN / 10){
                    r = 0;
                    break;
                }
                r = r * 10 + x % 10;
                x /= 10;

            }
            return r;

        }

};
