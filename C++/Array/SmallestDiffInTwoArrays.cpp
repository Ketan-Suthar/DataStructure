
pair<int, int> findSmallestDiffernece(int *arr1, int *arr2)
{
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int m = sizeof(arr2) / sizeof(arr2[0]);
	pair<int, int> answer;
	int diff = INT_MAX;
	int ni = 0, mi = 0;
	while(ni < n && mi < m)
	{
		int currDiff = abs(arr1[ni] - arr2[mi]);
		if(currDiff < diff)
		{
			answer = {arr1[ni], arr2[mi]};
			diff = currDiff;
		}
		if(arr1[ni] < arr2[mi])
			ni++;
		else if(arr1[ni] > arr2[mi])
			mi++;
		else
			break;
	}
	return answer;
}