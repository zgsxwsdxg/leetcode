class Solution {
    public:
        string multiply(string num1, string num2) {
            vector<int> records(num1.size() + num2.size() );
            for(int i = num1.size() - 1; i >= 0; --i){
                for(int j = num2.size() - 1; j >= 0; --j){
                    records[j + i + 1] += (num1[i] - '0') * (num2[j] - '0');
                }
            }
            int flag = 0;
            int pos = records.size() - 1;
            for(; pos >= 0; --pos){
                records[pos] += flag;
                flag = records[pos] / 10;
                records[pos] %= 10;
            }
            string res = "";
            pos = 0;
            while(pos < records.size() && records[pos] == 0){
                ++pos;
            }
            for(; pos < records.size(); ++pos){
                res += static_cast<char>(records[pos] + '0');
            }
            if(res == "") res = "0";
            return res;
        }
};
