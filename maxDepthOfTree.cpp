/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int maxDepth(struct TreeNode* root) {
	int left = 0;
	int right = 0;
	if (!root)
		return 0;
	else
	{
		left = maxDepth(root->left);
		right = maxDepth(root->right);
		return 1 + (left >= right ? left : right);
	}

	//give attention to * when use recursive, because the pointer is changing.


	/* int left, right;
	if (root == NULL)
	return 0;
	else{
	left = maxDepth(root->left);
	right = maxDepth(root->right);
	return 1 + ((left>right)?left:right);
	}
	*/
}