class Solution {
    public:
        int numDecodings(string s) {
            if(s.size() <= 0) return 0;
            int f_2 = 1;
            int f_1 = 1;
            if(s[0] == '0') return 0;
            for(int i = 1;i < s.size(); ++i){
                int f = 0;
                if(s[i- 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')){
                    f += f_2;
                }
                if(s[i] != '0'){
                    f += f_1;
                }
                if(s[i] == '0' && !(s[i-1] == '1' || s[i-1] == '2')){
                    return 0;
                }
                f_2 = f_1;
                f_1 = f;
            }
            return f_1;
        }
};
