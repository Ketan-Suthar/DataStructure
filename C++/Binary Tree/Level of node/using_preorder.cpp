void getLevelHelper(struct Node *node, int target,int dis, int &level)
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
int getLevel(struct Node *node, int target)
{
	int level = 0;
	getLevelHelper(node, target, 1, level);
	return level;
}
