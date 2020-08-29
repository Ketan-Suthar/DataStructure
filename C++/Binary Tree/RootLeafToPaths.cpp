void fun(Node* root)
{
    // Code here
    if(!root)
        return;
    static vector<Node*> arr;
    arr.push_back(root);
    fun(root->left);
    if(root->left==nullptr && root->right==nullptr)
    {
        for(auto it=arr.begin(); it!=arr.end();it++)
            cout << (*it)->data << " ";
        cout<<"#";
    }
    fun(root->right);
    arr.pop_back();
}
void printPaths(Node *root)
{
    fun(root);
    cout<<"\n";
}