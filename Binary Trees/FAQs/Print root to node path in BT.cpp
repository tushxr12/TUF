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
    void solve(vector<int> &currPath, vector<vector<int>> &ans, TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        currPath.push_back(root->data);
        if (!root->left && !root->right)
            ans.push_back(currPath);
        else
        {
            solve(currPath, ans, root->left);
            solve(currPath, ans, root->right);
        }
        currPath.pop_back();
    }

public:
    vector<vector<int>> allRootToLeaf(TreeNode *root)
    {
        // your code goes here
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> currPath;
        solve(currPath, ans, root);
        return ans;
    }
};