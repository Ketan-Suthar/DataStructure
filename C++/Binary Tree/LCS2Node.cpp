Node* lca(Node* r ,int n1 ,int n2 )
{
   //Your code here 
   if(!r)   return nullptr;
   if(r->data==n1 || r->data==n2)
        return r;
    Node *left = lca(r->left,n1,n2);
    Node *right = lca(r->right,n1,n2);
    if(left!=nullptr && right!=nullptr)
        return r;
    else
        return left?left:right;
}