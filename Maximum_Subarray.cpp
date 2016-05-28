class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int gsum = INT_MIN/2;
            int lsum = INT_MIN/2;
            for(auto num : nums){
                lsum = std::max(num, lsum + num);
                gsum = std::max(gsum, lsum);
            }
            return gsum;
        }
};


using namespace std;
template<typename T>
struct pair3T
{

	T posstart;
	T posend;
	T sum;
	pair3T(T start, T end, T val):posstart(start), posend(end), sum(val){
	}
	friend std::ostream& operator<< <T>(std::ostream& out, const pair3T& p3);
};
typedef pair3T<int> pair3i;
class MaximumSubarray
{
	public:
		pair3i find(vector<int>& array){
			return findMax(array, 0, array.size() - 1);
		}
	private:
		pair3i findMax(vector<int>& array, int left, int right){
			if (left > right) return pair3i(-1, -1, INT_MIN);
			if (left == right) return pair3i(left, right, array[left]);
			int mid = left + (right - left) / 2;
			pair3i resultleft = findMax(array, left, mid);
			pair3i resultright = findMax(array, mid + 1, right);
			pair3i resultcrossmid = findCrossmid(array, left, mid, right);
			if (resultleft.sum > resultcrossmid.sum && resultleft.sum > resultright.sum){
				return resultleft;
			}
			else if (resultright.sum > resultcrossmid.sum && resultright.sum > resultleft.sum){
				return  resultright;
			}
			else{
				return resultcrossmid;
			}
		}
		pair3i findCrossmid(vector<int>& array, int left, int mid, int right){
			int leftsum = array[mid];
			int sum = 0;
			int leftindex = mid;
			int rightindex = mid;
			for (int i = mid ; i >= left; --i){
				sum += array[i];
				if (sum > leftsum){
					leftsum = sum;
					leftindex = i;
				}
			}
			int rightsum = array[mid];
			sum = 0;
			for (int i = mid ; i <= right; ++i){
				sum += array[i];
				if (sum > rightsum){
					rightsum = sum;
					rightindex = i;
				}
			}
			return pair3i(leftindex, rightindex, leftsum + rightsum -array[mid]);
		}
	private:
};
