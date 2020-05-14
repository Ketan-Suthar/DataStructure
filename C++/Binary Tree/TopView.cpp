void topView(struct Node *root)
{

   if(!root)
        return;
    queue<pair<Node*, int>> q;
    map<int, vector<int>> m;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        Node *p = q.front().first;
        int v = q.front().second;
        q.pop();
        if(p->left)
            q.push(make_pair(p->left, v-1));
        if(p->right)
            q.push(make_pair(p->right, v+1));
            
        m[v].push_back(p->data);
    }
    
    for(auto it = m.begin(); it!=m.end(); it++)
            cout << it->second.front() << " ";

}