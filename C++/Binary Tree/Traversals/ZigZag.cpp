void zigZagTraversal(Node* root)
{
	// Code here
	if(!root)   return;
	stack<Node*> s1,s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
	    while(!s1.empty())
	    {
	        Node *p = s1.top();
	        s1.pop();
	        cout << p->data << " ";
	        if(p->left)
	            s2.push(p->left);
	        if(p->right)
	            s2.push(p->right);
	    }
	    while(!s2.empty())
	    {
	        Node *p = s2.top();
	        s2.pop();
	        cout << p->data << " ";
	        if(p->right)
	            s1.push(p->right);
	        if(p->left)
	            s1.push(p->left);
	    }
	}
}