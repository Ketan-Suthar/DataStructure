class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> result(k);
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i=0; i < points.size(); i++)
        {
            pair<int, int> p;
            p.first = points[i][0];
            p.second = points[i][1];
            pq.push(make_pair((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]),p));
            if(pq.size() > k)
                pq.pop();
        }
        int i=0;
        while(!pq.empty())
        {
            result[i] = vector<int>(2);
            result[i][0] = pq.top().second.first;
            result[i][1] = pq.top().second.second;
            ++i;
            pq.pop();
        }
        return result;
    }
};