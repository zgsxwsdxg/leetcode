class Solution{
    public:
        bool isOneEditDistance(string& s, string t){
            int slen = s.size(), tlen = t.size();
            if (abs(slen - tlen) > 1) return false;
            if (tlen > slen){
                return isOneEditDistance(t, s);
            }
            // slen >= tlen;
            int j = 0;
            while (j < tlen && s[j] == t[j]){
                ++j;
            }
            int i = j + 1;
            j += (int)(slen == tlen);
            while (j < tlen){
                if (s[i] != t[j])
                    return false;
                ++i, ++j;
            }
            return true;
        }
}
