//given two strings s and t, write a function to determine if t is an anagram of s.
//
//for example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.

bool isAnagram(char* s, char* t) {
	if (strlen(s) != strlen(t))
		return false;
	if (strcmp(s, t) == 0)
		return true;
	char* p = s;
	char* pend = s + strlen(s) - 1;
	char* q = t;
	int map[26] = { 0 };
	while (pend - p >= 0){
		map[*p - 'a'] += 1;
		map[*q - 'a'] -= 1;
		++p;
		++q;
	}
	for (int i = 0; i != 26; ++i)
	{
		if (map[i]<0)
			return false;
	}
	return true;
}