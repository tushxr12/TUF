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
    void preOrderTraverse(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        ans.push_back(root->data);
        preOrderTraverse(root->left, ans);
        preOrderTraverse(root->right, ans);
    }

public:
    vector<int> preorder(TreeNode *root)
    {
        // your code goes here
        vector<int> ans;
        if (!root)
            return ans;
        preOrderTraverse(root, ans);
        return ans;
    }
};