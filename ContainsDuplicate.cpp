
//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice in the array, 
//and it should return false if every element is distinct.

//solution1 time(O(n^2))
bool containsDuplicate1(int* nums, int numsSize) {
	int* p = nums;
	int* q = nums + numsSize - 1;
	int* cursor = NULL;
	bool result = true;
	while (q - p>0)
	{
		cursor = p + 1;
		while (q - cursor >= 0)
		{
			if (*cursor == *p)
				return true;
			else
			{
				++cursor;
			}
		}
		++p;
	}
	return false;

}

//solution2 time(O(n))
bool containsDuplicate2(int* nums, int numsSize) {
	bool result = true;
	if (numsSize == 0)
		result = false;
	int hashkey[numsSize];
	int hashvalue[numsSize];
	for (int k = 0; k != numsSize; ++k)
		hashvalue[k] = 0;

	for (int i = 0; i != numsSize; ++i)
	{
		int id = (nums[i] + numsSize) % numsSize;
		if (hashvalue[id] == 0)
		{
			++hashvalue[id];
			hashkey[id] = nums[i];
		}
		else if (hashkey[id] == nums[i])
			++hashvalue[id];
		else
		{
			while (hashvalue[id] != 0)
			{
				id = (id + 1) % numsSize;
			}
			hashkey[id] = nums[i];
			hashvalue[id] += 1;
		}
	}
	for (int j = 0; j != numsSize; ++j)
	{
		if (hashvalue[j] >= 2)
		{
			result = true;
			break;
		}
		else
			result = false;
	}
	return result;
}