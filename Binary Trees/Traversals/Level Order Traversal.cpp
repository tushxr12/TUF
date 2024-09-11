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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // your code goes here
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *nextNode = q.front();
                q.pop();
                if (nextNode->left)
                    q.push(nextNode->left);
                if (nextNode->right)
                    q.push(nextNode->right);
                level.push_back(nextNode->data);
            }
            ans.push_back(level);
        }

        return ans;
    }
};