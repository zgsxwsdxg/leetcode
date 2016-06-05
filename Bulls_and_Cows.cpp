class Solution {
	public:
		string getHint(string secret, string guess) {
			vector<int> record(10,0);
			int A = 0;
			int B = 0;
			for(size_t i = 0; i < secret.size(); ++i){
				if(secret[i] == guess[i]) A++;
				else{
					if(record[secret[i] - '0'] < 0 ){
						++B;
					}
					++record[secret[i] - '0'];
					if(record[guess[i] - '0'] > 0){
						++B;
					}
					--record[guess[i] - '0'];
				}

			}
			char r[16] = {0};
			sprintf(r,"%dA%dB",A,B);
			// since c++11
		    // string res;
		    // res = to_string(A) + "A" + to_string(B) + "B"; 
			// return res;
			return string(r);
		}
};
