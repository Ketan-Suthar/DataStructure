void printKdistance(struct Node *r, int k)
{
  // Your code here
  if(r==nullptr)
    return;
    
    if(k<0)
        return;
    if(k==0)
        cout<<r->data << " ";
    else
    {
        printKdistance(r->left, k-1);
        printKdistance(r->right, k-1);
    }
}