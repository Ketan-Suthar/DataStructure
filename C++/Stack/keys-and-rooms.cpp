class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int size = rooms.size();
        bool vis[size];
        for(int i=0; i<size; i++)
            vis[i]=0;
        vis[0]=1;
        stack<int> stk;
        stk.push(0);
        while(!stk.empty())
        {    
            int room = stk.top();
            stk.pop();
            for(int key: rooms[room])
                if(!vis[key])
                {
                    vis[key] = 1;
                    stk.push(key);
                }
        }
        
        for(int i=0; i<size; i++)
            if(!vis[i])
                return false;
        return true;
    }
};