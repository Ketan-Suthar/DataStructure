void swap(Node *&node1,Node *&node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void reverseAlternateHelper(Node *node1,Node *node2, bool level)
{
    if(!node1 || !node2) return;
    if(level)
        swap(node1, node2);
    reverseAlternateHelper(node1->left, node2->right, !level);
    reverseAlternateHelper(node1->right, node2->left, !level);
}

void reverseAlternate(Node *root)
{
    if(!root) return;
    reverseAlternateHelper(root->left, root->right, 1);
}