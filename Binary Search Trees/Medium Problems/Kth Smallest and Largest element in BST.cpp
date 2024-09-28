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
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

public:
    vector<int> kLargesSmall(TreeNode *root, int k)
    {
        // your code goes here
        vector<int> ans;
        inorder(root, ans);
        int n = ans.size();
        return {ans[k - 1], ans[n - k]};
    }
};