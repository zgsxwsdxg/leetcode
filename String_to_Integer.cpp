int myAtoi(char* str) {
	if(str == NULL) return 0;
	while(*str == ' ') ++str; // trim
	int f = 1;
	double res = 0;
	if(*str == '+') ++str; // + 
	else if(*str == '-'){  // -
		++str;
		f = -1;
	}
	while(*str){
		if(*str > '9' || *str < '0') break;
		res = res * 10 + f*(*str - '0');
		if(res < INT_MIN) return INT_MIN;
		if(res > INT_MAX) return INT_MAX;
		++str;
	}
	return res;
}
