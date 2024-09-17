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
    int widthOfBinaryTree(TreeNode *root)
    {
        // your code goes here
        if (!root)
            return 0;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        int ans = 0;

        while (!q.empty())
        {
            int mini = q.front().second;
            int first = 0, last = 0;
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int curr = q.front().second - mini;
                TreeNode *currNode = q.front().first;
                q.pop();

                if (i == 0)
                    first = curr;
                if (i == size - 1)
                    last = curr;

                if (currNode->left)
                    q.push({currNode->left, curr * 2 + 1});
                if (currNode->right)
                    q.push({currNode->right, curr * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};