bool isFoldableHelper(Node *leftTree, Node *rightTree)
{
    if(!leftTree && !rightTree)
        return 1;
    if(!leftTree || !rightTree)
        return 0;
    return (isFoldableHelper(leftTree->left, rightTree->right) &&
            isFoldableHelper(leftTree->right, rightTree->left));
}

bool IsFoldable(Node* root)
{
    if(!root)
        return 1;
    return isFoldableHelper(root->left, root->right);
}