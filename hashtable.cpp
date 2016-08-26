//
//169. Majority Element
//Given an array of size n, find the majority element.The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
//
//You may assume that the array is non - empty and the majority element always exist in the array




int majorityElement(int* nums, int numsSize) {
	int i = 0;
	int idx;
	int hashKey[numsSize];
	int hashvalue[numsSize];
	int halfsize = numsSize / 2;
	int majority;
	for (int i = 0; i != numsSize; ++i)
	{
		hashvalue[i] = 0;
	}
	for (int i = 0; i != numsSize; ++i)
	{
		int idx = (nums[i] + 5 * numsSize) % numsSize;
		if (hashvalue[idx] == 0)
		{
			hashKey[idx] = nums[i];
			hashvalue[idx] += 1;
		}
		else if (nums[i] == hashKey[idx])
			++hashvalue[idx];
		else
		{
			while (hashvalue[idx] != 0)
			{
				idx = (idx + 1) % numsSize;
			}
			hashKey[idx] = nums[i];
			++hashvalue[idx];
		}

	}
	for (int i = 0; i != numsSize; ++i)
	{
		if (hashvalue[i]>halfsize)
		{
			majority = hashKey[i];
			break;
		}
	}
	return majority;
}