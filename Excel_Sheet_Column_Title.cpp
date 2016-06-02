class Solution {
    public:
        string convertToTitle(int n) {
            string res;
            if(n <= 0) return res;
            do{
                res = char('A' + (n-1)%26) + res ;
                n = (n-1) / 26;
            }while(n);
            return res;
        }
};
