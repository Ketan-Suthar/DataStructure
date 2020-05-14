class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        
        priority_queue<pair<int,int> >pq;
        
        for(auto it=mp.begin();it!=mp.end();it++)
            pq.push({it->second,it->first});

        vector<int>vec;
        int c =0;
        while(!pq.empty() && c!=k)
        {
            pair<int,int> p = pq.top();
            pq.pop();
            c++;
            vec.push_back(p.second);
        }
        return vec;
    }
};
static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();