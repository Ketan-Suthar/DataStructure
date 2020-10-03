int isPairPresent(struct Node *root, int target)
{
    static unordered_set<int> map;
    // for(auto it = map.begin(); it != map.end(); it++)
    //     cout << (*it) << ' ';
    // cout<<'\n';
    if(!root)
        return 0;
    if(map.find(target - (root->data)) != map.end())
        return 1;
    map.insert(root->data);
    if(isPairPresent(root->left, target))
        return 1;
    return isPairPresent(root->right, target);
}