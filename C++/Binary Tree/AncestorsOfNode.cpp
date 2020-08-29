bool printAncestors(struct Node *r, int target)
{
   if(r!=nullptr)
   {
       if(r->data == target)
            return 1;
        if(printAncestors(r->left, target) || printAncestors(r->right,target))
        {
            cout << r->data << " ";
            return 1;
        }
        return 0;
   }
   return 0;
}
