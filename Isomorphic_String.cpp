class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if(s.size() != t.size()) return false;
            int a[256] = {0};
            int b[256] = {0};
            for(size_t i = 0; i < s.size(); ++i){
                if(a[s[i]] == b[t[i]]){
                    a[s[i]] = i + 1;
                    b[t[i]] = i + 1;
                }
                else{
                    return false;
                }
            }
            return true;
        }
};
