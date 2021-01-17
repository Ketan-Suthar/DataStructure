class MedianFinder
{
private:
    int  min_size, max_size;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {
        min_size = max_size = 0;
    }
    
    void addNum(int num) 
    {
        if(!min_size && !max_size)
        {
            max_heap.push(num);
            max_size = max_heap.size();
            return;
        }
        else
        {
            if(max_size > 0 && num < max_heap.top())
                max_heap.push(num);
            else
                min_heap.push(num);
            min_size = min_heap.size();
            max_size = max_heap.size();
            
            int diff = abs(min_size - max_size);
            if(diff <= 1)
                return;
            int temp;
            if(min_size > max_size)
            {
                temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
            }
            else
            {
                temp = max_heap.top();
                max_heap.pop();
                min_heap.push(temp);
            }
            min_size = min_heap.size();
            max_size = max_heap.size();
            cout<<min_size<<' '<<max_size<<'\n';
        }
    }
    
    double findMedian() 
    {
        if(!min_size && !max_size)
            return 0.0;
        double min_top = 0;
        if(min_size)
            min_top = min_heap.top();
        double max_top = 0;
        if(max_size)
            max_top = max_heap.top();
        cout<<min_top<<' '<<max_top<<'\n';
        if(min_size == max_size)
            return ((min_top + max_top)/2.0);
        if(min_size > max_size)
            return min_top;
        return max_top;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */