class Solution {
    public:
        bool isPowerOfFour(int num) {
            if(num <= 0) return false;
            int p4[16] = {0};
            for(int i = 0; i < 16; ++i){
                p4[i] = (1 << (2 * i));
            }
            for(int i = 0; i < 16; ++i){
                if(num == p4[i]){
                    return true;
                }
            }
            return false;
        }
};

class Solution {
    public:
        bool isPowerOfFour(int num) {
            if(num <= 0) return false;
            if(num & (num - 1)) return false;
            int x = log2(num);
            return x%2 == 0;
        }
};
