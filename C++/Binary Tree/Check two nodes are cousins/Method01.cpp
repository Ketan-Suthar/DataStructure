void getLevelHelper(Node *node, int target,int dis, int &level)
{
    if(node)
	{
	   if(node->data == target)
	   {
	       level = dis;
	       return;
	   }
	   getLevelHelper(node->left, target, dis+1, level);
	   getLevelHelper(node->right, target, dis+1, level);
	}
}
int getLevel(Node *node, int target)
{
	int level = 0;
	getLevelHelper(node, target, 1, level);
	return level;
}
void findParent(Node *root, int a, Node *parent, Node **node)
{
    if(!root) return;
    if(root->data == a)
    {
        (*node) = parent;
        return;
    }
    findParent(root->left, a, root, node);
    findParent(root->right, a, root, node);
}
bool isCousins(Node *root, int a, int b)
{
    if(!root) return 0;
    if(root->data==a || root->data==b)
        return 0;
    int level_a = -1, level_b = -1;
    level_a = getLevel(root, a);
    level_b = getLevel(root, b);
    // cout << level_a << ' ' << level_b << endl;
    if(level_a != level_b)
        return 0;
    Node *a_parent = root, *b_parent = root;
    findParent(root, a, nullptr, &a_parent);
    findParent(root, b, nullptr, &b_parent);
    // cout << a_parent->data << ' ' << b_parent->data << endl;
    if(a_parent == b_parent)
        return 0;
    return 1;
}