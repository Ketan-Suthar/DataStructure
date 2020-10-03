/*
Given two arrays X[] and Y[] of size M and N respectively.
Find number of pairs such that xy > yx
where x is an element from X[] and y is an element from Y[].
*/

ll countPairs(int X[], int Y[], int m, int n)
{
    int hash[5] {0};
    ll result = 0;
    sort(Y, Y+n);
    for(int i=0; i < n; i++)
        if(Y[i] < 5)
            hash[Y[i]]++;
    for(int i=0; i<m; i++)
    {
        if(X[i]==0) continue;
        if(X[i]==1)
        {
            result += hash[0];
            continue;
        }
        int *p = upper_bound(Y, Y+n, X[i]);
        result += ((Y+n) - p) + hash[0] + hash[1];
        
        if(X[i] == 2)
            result -= (hash[3] + hash[4]);
        if(X[i] == 3)
            result += hash[2];
    }
    return result;
}