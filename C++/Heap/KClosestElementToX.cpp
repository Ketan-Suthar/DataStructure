class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        priority_queue<pair<int, int>> q;
        vector<int> result(k);
        for(int num: arr)
        {
            q.push({ abs(x - num), num});
            if(q.size() > k)
                q.pop();
        }
        int i=0;
        while(q.size() > 0)
        {
            result[i++] = q.top().second;
            q.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};