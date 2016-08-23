bool canConstruct(char* ransomNote, char* magazine) {
	if (strlen(ransomNote)>strlen(magazine))
		return false;
	int map[26] = { 0 };
	char* p = magazine;
	for (int i = 0; i != strlen(magazine); ++i)
	{
		map[*p - 'a'] += 1;
		++p;
	}
	p = ransomNote;
	for (int i = 0; i != strlen(ransomNote); ++i)
	{
		map[*p - 'a'] -= 1;
		if (map[*p - 'a']<0)
			return false;
		++p;
	}
	return true;
}