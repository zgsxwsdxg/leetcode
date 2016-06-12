//版本一： 递归
class Solution {
    public:
        bool isScramble(string s1, string s2) {
            return isS(s1, s2);
        }
    private:
        bool isS(string& s1,string& s2){
            int len = s1.size();
            if(len == 1 && s1 == s2) return true;
            if(equal(s1,s2)){
                for(int i = 1; i < len; ++i){
                    string s11 = s1.substr(0,i);
                    string s12 = s1.substr(i);
                    string s21 = s2.substr(0,i);
                    string s22 = s2.substr(i);
                    bool flag = isS(s11, s21) && isS(s12, s22);
                    if(flag) return true;
                    s21 = s2.substr(len -i);
                    s22 = s2.substr(0, len - i);
                    flag = isS(s11, s21) && isS(s12, s22);
                    if(flag) return true;
                }
            }
            return false;
        }
        bool equal(string& s1, string& s2){
            int ch[256] = {0};
            for(size_t i = 0; i < s1.size(); ++i){
                ++ch[s1[i]];
                --ch[s2[i]];
            }
            for(int i = 0; i < 256; ++i){
                if(ch[i] != 0)
                    return false;
            }
            return true;
        }
};
// 版本二 ： dp
// how to dp
