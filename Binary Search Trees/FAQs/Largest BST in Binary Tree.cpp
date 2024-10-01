/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
class NodeValue
{
	public:
	int maxNode, minNode, maxSize;

	NodeValue(int minNode, int maxNode, int maxSize)
	{
		this->maxNode = maxNode;
		this->minNode = minNode;
		this->maxSize = maxSize;
	}
};
class Solution{
	private:
		NodeValue largestBSTSubtreeHelper(TreeNode* root)
		{
			if(!root)
				return NodeValue(INT_MAX, INT_MIN, 0);
			
			auto left = largestBSTSubtreeHelper(root->left);
			auto right = largestBSTSubtreeHelper(root->right);

			if(left.maxNode < root->data && root->data < right.minNode)
			{
				//Valid BST
				return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
			}
			return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
		}
	public:
		int largestBST(TreeNode* root){
			//your code goes here
			return largestBSTSubtreeHelper(root).maxSize;
		}
};
