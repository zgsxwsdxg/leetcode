class Solution {
	public:
		bool isPerfectSquare(int num) {
			int left = 0;
			int right = num  ;
			int mid = left + (right - left) / 2;
			while(left <= right){
				mid = left + (right - left) / 2;
				if(mid * mid == num ) return true;
				else if(mid != 0 && mid > num / mid) right = mid - 1;
				else left = mid + 1;
			}
			return false;

		}
};
