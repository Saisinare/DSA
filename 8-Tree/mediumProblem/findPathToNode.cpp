
bool traverse(TreeNode<int> *root, int x,vector<int>& ans)
{
	if(root == nullptr){
		return false;
	} 
	ans.push_back(root->data);
	if(root->data == x) return true;
	bool left = traverse(root->left,x,ans);
	bool right = traverse(root->right,x,ans);
	if(!left && !right ){
	ans.pop_back();
	return false;	
	} 
	return true;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> ans;
	traverse(root,x,ans);
	return ans;
}











