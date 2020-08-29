bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(!r1 && !r2)
        return true;
    if(!r1 || !r2)
        return false;
    return ((r1->data == r2->data) && (isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right)));
}

bool isSubTree(Node* T, Node* S) 
{
    // Your code here
    // return 1 if S is subtree of T else 0
    if(!S)
        return 1;
    if(!T)
        return 0;
    if(isIdentical(T,S))
        return 1;
    return isSubTree(T->left, S) || isSubTree(T->right, S);
}