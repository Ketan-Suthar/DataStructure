Node* LCA(Node *root, int n1, int n2)
{
   Node *temp = root;
    while(temp)
    {
        if(temp->data > n1 && temp->data > n2)
            temp = temp->left;
        else if(temp->data < n1 && temp->data < n2)
            temp = temp->right;
        else
            break;
    }
    return temp;
}