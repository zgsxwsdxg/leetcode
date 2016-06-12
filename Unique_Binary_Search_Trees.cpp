// 版本一 ：dp
class Solution {
    public:
        int numTrees(int n) {
            vector<int> f(n+1, 0);
            f[0] = 1;
            for(int i = 1; i <=n; ++i){
                for(int j = 0; j < i/2; ++j){
                    f[i] += 2*f[j]*f[i - 1 -j];
                }
                if(i&1){
                    f[i] += f[i/2] * f[i/2];
                }
            }
            return f[n];
        }
};

//版本二： 公式
// f(n) = C(n,2n) / n+1;  推到见严蔚DS
