/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution
{
private:
    void postorderTraverse(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        postorderTraverse(root->left, ans);
        postorderTraverse(root->right, ans);
        ans.push_back(root->data);
    }

public:
    vector<int> postorder(TreeNode *root)
    {
        // your code goes here
        vector<int> ans;
        if (!root)
            return ans;
        postorderTraverse(root, ans);
        return ans;
    }
};