vector <int> countDistinct (int A[], int n, int k)
{
    //code here.
    vector <int> result;
    unordered_map<int,int> mp;
    for(int i=0;i<k;i++)
    {
        mp[A[i]]++;
    }
    result.push_back(mp.size());
    for(int i=1;i<n-k+1;i++)
    {
        mp[A[i+k-1]]++;
        mp[A[i-1]]--;
        if(mp[A[i-1]]==0)
        {
            mp.erase(A[i-1]);
        }
        result.push_back(mp.size());
    }
    return result;
}