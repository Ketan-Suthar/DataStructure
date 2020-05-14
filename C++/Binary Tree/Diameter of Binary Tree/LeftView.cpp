void leftView(Node *root)
{
   // Your Code here
    if(!root) return;
    queue<Node*> q;
    int lev = 0;
    map<int, vector<int>> res;
    q.push(root);
    q.push(NULL);
    while(q.size()!=1)
    {
        root = q.front();
        q.pop();
        if(root!=NULL)
          res[lev].push_back(root->data);
        else if(root==NULL)
        {
            ++lev;
          q.push(NULL);
          continue;
        }
          
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    for(auto it=res.begin(); it!=res.end(); it++)
        cout << it->second.front() << " ";
}
