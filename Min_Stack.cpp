class MinStack {
	public:
		/** initialize your data structure here. */
		MinStack() {
			p = new int[10000];//正无穷
			q = new int[5000];//正无穷
			p[0] = INT_MAX;
			q[0] = INT_MAX;
			posp = 0;
			posq = 0;
		}
		~MinStack() {
			if(p) delete[] p;
			p = NULL;
			if(q) delete[] q;
			q = NULL;
			posp = -1;
			posq = -1;
		}
		void push(int x) {
			p[++posp] = x;
			if(x <= q[posq]){
				q[++posq] = x;
			}
		}
		void pop() {
			assert(posp > 0);
			if(p[posp] == q[posq]){
				--posq;
			}
			--posp;
		}
		int top() {
			assert(posp > 0);
			return p[posp];
		}
		int getMin() {
			assert(posq > 0);
			return q[posq];
		}
	private:
		int *p;
		int *q;
		int posp;
		int posq;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 **/

// m2
class MinStack {
	public:
		/** initialize your data structure here. */
		MinStack() {
			min = INT_MAX;
		}
		void push(int x) {
			if(x <= min){
				st.push(min);
				min = x;
			}
			st.push(x);
		}
		void pop() {
			if(st.empty()) return ;
			if(min == st.top()){
				st.pop();
				min = st.top();
				st.pop();
			}
			else{
				st.pop();
			}
		}
		int top() {
			return st.top();
		}
		int getMin() {
			return min;
		}
	private:
		int min;
		stack<int> st;

};

