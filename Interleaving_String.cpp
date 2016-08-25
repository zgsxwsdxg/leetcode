// Time Limit Exceeded
class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            if(s1.size() + s2.size() != s3.size()) return false;
            return isI(s1.c_str(),0, s1.size() - 1, s2.c_str(), 0, s2.size() -  1, s3.c_str(), 0, s3.size() - 1);
        }
        bool isI(const char* s1, int left1, int right1, \
                const char* s2, int left2, int right2, \
                const char* s3, int left3, int right3){
            if (left1 > right1){
                while (left2 <= right2 && left3 <= right3){
                    if (s2[left2] != s3[left3]) break;
                    ++left2, ++left3;
                }
                return left2>right2 && left3>right3;
            }
            if (left2 > right2){
                while (left1 <= right1 && left3 <= right3){
                    if (s1[left1] != s3[left3]) break;
                    ++left1, ++left3;
                }
                return left1 >right1 && left3>right3;
            }
            if (s1[left1] == s3[left3] || s2[left2] == s3[left3]){
                if (s1[left1] == s3[left3] && s2[left2] == s3[left3])
                    return isI(s1, left1 + 1, right1, s2, left2, right2, s3, left3 + 1, right3) || \
                        isI(s1, left1, right1, s2, left2 + 1, right2, s3, left3 + 1, right3);
                else if (s1[left1] == s3[left3])
                    return isI(s1, left1 + 1, right1, s2, left2, right2, s3, left3 + 1, right3);
                else
                    return isI(s1, left1, right1, s2, left2 + 1, right2, s3, left3 + 1, right3);
            }
            return false;
        }
};

//dp2
