bool canConstruct(char* ransomNote, char* magazine) {
	int rnum = strlen(ransomNote);
	int mnum = strlen(magazine);
	if (rnum>mnum)
		return false;
	else
	{
		char* cursor = magazine;
		char* tail = magazine + mnum - 1;
		while (tail - cursor >= (rnum - 1))
		{
			if (strncmp(cursor, ransomNote, rnum) == 0)
			{
				return true;
			}
			++cursor;
		}
		return false;
	}
}