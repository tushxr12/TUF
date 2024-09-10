/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	private:
		void inorderTraverse(TreeNode* root, vector<int> &ans)
		{
			if(!root)
				return;
			
			inorderTraverse(root->left,ans);
			ans.push_back(root->data);
			inorderTraverse(root->right, ans);
		}

	public:
		vector<int> inorder(TreeNode* root){
	        //your code goes here
			vector<int> ans;
			if(!root)
				return ans;
			inorderTraverse(root,ans);
			return ans;
		}
};