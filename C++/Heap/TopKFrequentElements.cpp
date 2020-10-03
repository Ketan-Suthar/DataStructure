class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;
        for(int x: nums)
            map[x]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> q;
        
        for(auto itr = map.begin(); itr!=map.end(); itr++)
        {
            q.push({itr->second, itr->first});
            if(q.size() > k)
                q.pop();
        }
        vector<int> result;
        while(q.size() > 0)
        {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};