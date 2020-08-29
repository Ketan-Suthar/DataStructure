int _min = 65500;
void push(int a)

{
     //add code here.
    if(!s.size())
    {
        s.push(a);
        _min = a;
    }
    else
    {
        if(a >= _min)
            s.push(a);
        else
        {
            s.push((2*a)-_min);
            _min = a;
        }
    }
    
}

bool isFull(int n)
{
    //add code here.
    return s.size()==n;
}

bool isEmpty()
{
    //add code here.
    return s.size()==0;
}


int pop()
{
    //add code here.
    if(s.size()==0)
        return -1;
    if(s.top() >= _min)
        s.pop();
    else
    {
        _min = (2*_min) - s.top();
        s.pop();
    }
}

int getMin()
{
   //add code here.
   if(!s.size())
        return 0;
    return _min;
}
