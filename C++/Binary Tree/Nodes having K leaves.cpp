int fun(Node *ptr, int k, int &c)
{
    if(ptr==nullptr)    return 0;
    if(ptr->left==nullptr && ptr->right==nullptr)
        return 1;
    int l = fun(ptr->left, k,c);
    int r = fun(ptr->right, k,c);
    int t = l+r;
    if(t==k)
    {
        cout<<ptr->data<<" ";
        ++c;
    }
    return t;
}

void btWithKleaves(Node *ptr, int k)
{ 
    //your code here.
    int cnt=0;
    fun(ptr,k,cnt);
    if(cnt==0)
        cout<<"-1";
    cout<<"\n";
}
