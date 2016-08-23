//Excel Sheet Column Number
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example :
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28



int titleToNumber(char* s) {
	char *p = s;
	char *q = s + strlen(s) - 1;
	int num = 0;
	int result = 0;
	while (q - p >= 0)
	{
		result += pow(26, num)*(*q - '@');
		++num;
		--q;
	}
	return result;
}