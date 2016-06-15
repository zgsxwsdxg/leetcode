class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            addingpar(res, "", n, 0);
            return res;
        }
        void addingpar(vector<string> &v, string str, int n, int m){
            if(n==0 && m==0) {
                v.push_back(str);
                return;
            }
            if(m > 0){ addingpar(v, str+")", n, m-1);  }
            if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
        }
};

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            if(n <= 0) return res;
            gen(res,0,0,n,"");
            return res;
        }
    private:
        void gen(vector<string>& res,int left, int right, int n, string ret){
            if(left == n && right == n){
                res.emplace_back(ret);
            }
            if(left < n){
                gen(res, left + 1, right, n, ret + '(');
            }
            if(left > right){
                gen(res, left, right + 1, n, ret + ')');
            }
        }
};
