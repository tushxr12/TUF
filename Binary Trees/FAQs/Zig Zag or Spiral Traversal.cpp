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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        // your code goes here
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                int index = leftToRight ? i : (size - i - 1);

                level[index] = node->data;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;
    }
};