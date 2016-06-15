class Solution {
    public:
        int romanToInt(string s) {
            int res = 0;
            int r2i[26] = {0};
            r2i['I' - 'A'] = 1;
            r2i['V' - 'A'] = 5;
            r2i['X' - 'A'] = 10;
            r2i['L' - 'A'] = 50;
            r2i['C' - 'A'] = 100;
            r2i['D' - 'A'] = 500;
            r2i['M' - 'A'] = 1000;
            for(size_t i = 1; i < s.size(); ++i){
                int flag = 2 * static_cast<int>(r2i[s[i - 1]-'A'] >= r2i[s[i]-'A']) - 1;
                res += r2i[s[i - 1] - 'A'] * flag;
            }
            res += r2i[s[s.size()-1] - 'A'];
            return res;
        }
};
