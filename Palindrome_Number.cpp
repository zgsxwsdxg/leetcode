class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0) return false;
            int e = 1;
            int y = x;
            while(y/10){
                e *= 10;
                y /= 10;
            }
            while(x  && x/e == x%10){
                x %= e;
                e /= 100;
                x /= 10;
            }
            return x == 0;
        }
};
