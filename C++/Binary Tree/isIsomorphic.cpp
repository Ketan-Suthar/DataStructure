bool isIsomorphic(Node *r1,Node *r2)
{
//add code here.
    if(!r1 && !r2)
        return true;
    if(!r1 || !r2)
        return false;

    return ((r1->data == r2->data) && 
        ( 
            (
                isIsomorphic(r1->left, r2->left) 
                && 
                isIsomorphic(r1->right, r2->right)
            )
            || 
            (
                isIsomorphic(r1->left, r2->right)
                && 
                isIsomorphic(r1->right, r2->left)
            )
        ));
}