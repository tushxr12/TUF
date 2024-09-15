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
public:
    vector<int> topView(TreeNode *root)
    {
        // your code goes here
        vector<int> ans;
        if (!root)
            return ans;

        map<int, int> mpp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            TreeNode *nodeInQueue = node.first;
            int line = node.second;

            if (mpp.find(line) == mpp.end())
                mpp[line] = nodeInQueue->data;

            if (nodeInQueue->left)
                q.push({nodeInQueue->left, line - 1});
            if (nodeInQueue->right)
                q.push({nodeInQueue->right, line + 1});
        }
        for (auto i : mpp)
            ans.push_back(i.second);
        return ans;
    }
};