class Solution {
    public:
        string getPermutation(int n, int k) {
            int a[]={1,2,3,4,5,6,7,8,9};
            int an = ann(n);
            return getP(a,n,k,an);
        }
        string getP(int* a,int len, int k, int an){
            if(len == 1) return to_string(a[0]);
            if(k == 1){
                string res = "";
                for(int i = 0; i < len; ++i){
                    res += to_string(a[i]);
                }
                return res;
            }
            string res = "";
            an /= len;
            int x = (k -1) / an;
            k = (k- 1) %an + 1;
            res += to_string(a[x]);
            ++x;
            for(; x < len; ++x){
                a[x - 1] = a[x];
            }
            return res + getP(a,len-1,k, an);
        }
        int ann(int n){
            int r = 1;
            while(n > 1){
                r *=n;
                --n;
            }
            return r;
        }
};

class Solution {
    public:
        string getPermutation(int n, int k) {
            int a[]={1,2,3,4,5,6,7,8,9};
            int ann = 1;
            for(int i = n ; i > 1; --i){
                ann *= i;
            }
            string res(n,'0');
            for(int i = 1; i <= n; ++i){
                ann /= (n - i + 1);
                int p = (k - 1) / ann;
                res[i - 1] =  char('0' + a[p]);
                for(++p; p < n; p++){
                    a[p - 1] = a[p];
                }
                k = ( k -1 ) % ann + 1;
            }
            return res;
        }
};
