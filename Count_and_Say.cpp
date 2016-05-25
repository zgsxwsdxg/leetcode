class Solution {
    public:
        string countAndSay(int n) {
            string res = "1";
            while(n > 1){
                string next;
                next.swap(res);
                int i = 0;
                while(i < next.size()){
                    size_t j = i + 1;
                    for(; j < next.size(); ++j){
                        if(next[i] != next[j]) break;
                    }
                    int n = j - i;
                    while(n){
                        res += '0' + n % 10;
                        n /= 10;
                    }
                    res += next[i];
                    i = j;
                }
                --n;
            }
            return res;
        }
};
