vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> res;
    list<int> que;
    for(int i=0;i<k;i++)
    {
        while(!que.empty() && arr[que.back()] <= arr[i])
            que.pop_back();
            
        que.push_back(i);
    }
    for(int i=k;i<n;i++)
    {
        res.push_back(arr[que.front()]);
        if(que.front() == (i-k))
            que.pop_front();
        while(!que.empty() && arr[que.back()] <= arr[i])
            que.pop_back();
            
        que.push_back(i);
    }
    res.push_back(arr[que.front()]);
    return res;
}
