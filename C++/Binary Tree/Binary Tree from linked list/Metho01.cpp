void convert(Node *head, TreeNode *&root)
{
    if(!head)
        return;
    root = new TreeNode(head->data);
    queue<TreeNode*> q;
    q.push(root);
    head = head->next;
    while(head)
    {
        TreeNode *parent = q.front();
        q.pop();
        TreeNode *left = nullptr, *right = nullptr;
        left = new TreeNode(head->data);
        parent->left = left;
        q.push(left);
        head = head->next;
        if(head)
        {
            right = new TreeNode(head->data);
            q.push(right);
            head = head->next;
        }
        parent->right = right;
    }
}
