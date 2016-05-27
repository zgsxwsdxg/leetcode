class Solution {
	public:
		string addBinary(string a, string b) {
			int f = 0;
			string  res;
			int posa = a.size() - 1;
			int posb = b.size() - 1;
			while(posa >=0 && posb >= 0){
				int t = a[posa] - '0' + b[posb] - '0' + f;
				f = t / 2;
				t = t % 2;
				res = static_cast<char>(t + '0') + res;
				--posa;
				--posb;
			}
			while(posa >= 0 && f){
				int t = a[posa] - '0'  + f;
				f = t / 2;
				t = t % 2;
				res = static_cast<char>(t + '0') + res;
				--posa;
			}
			res = a.substr(0, posa + 1) + res;
			while(posb >= 0 && f){
				int t = b[posb] - '0'  + f;
				f = t / 2;
				t = t % 2;
				res = static_cast<char>(t + '0') + res;
				--posb;
			}
			res = b.substr(0, posb + 1) + res;
			if(f) res = '1' + res;
			return res;
		}
};
