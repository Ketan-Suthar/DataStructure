class LRUCache
{
private:
    list<pair<int, int>> LRUCacheDeque;
    unordered_map<int, list<pair<int, int>>::iterator> LRUCacheHashMap;
    int size;
    int currentSize=0;
public:
    LRUCache(int capacity) 
    {
        size = capacity;
    }
    
    int get(int key)
    {
        if(key == 5)
        {
            for(auto const& p: LRUCacheHashMap)
                cout << p.first << " " << p.second->second << "\n";
        }
        if(LRUCacheHashMap.find(key) != LRUCacheHashMap.end())
        {
            int res = LRUCacheHashMap[key]->second; 
            put(key, LRUCacheHashMap[key]->second);
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value)
    {
        list<pair<int, int>>::iterator it;
        if(LRUCacheHashMap.find(key) != LRUCacheHashMap.end())
        {
            it = LRUCacheHashMap[key];
            LRUCacheDeque.erase(it);
            LRUCacheHashMap.erase(key);
            //--currentSize;
        }
        else
        {
            //cout << "in else "<<key<<" "<<value<<" "<<currentSize<<"\n";
            if(currentSize == size)
            {
                LRUCacheHashMap.erase(LRUCacheDeque.front().first);
                LRUCacheDeque.pop_front();
            }
            else
                ++currentSize;
            //LRUCacheDeque.push_back({key, value});
        }
        LRUCacheDeque.push_back({key, value});
        LRUCacheHashMap[key] = --LRUCacheDeque.end();
    }
};