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
    TreeNode *bfsToMapParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentMap, int start)
    {
        queue<TreeNode *> q;
        q.push(root);

        TreeNode *targetNode = new TreeNode(-1);

        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode->data == start)
                targetNode = currNode;

            if (currNode->left)
            {
                q.push(currNode->left);
                parentMap[currNode->left] = currNode;
            }

            if (currNode->right)
            {
                q.push(currNode->right);
                parentMap[currNode->right] = currNode;
            }
        }
        return targetNode;
    }

    int findMinTime(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentMap, TreeNode *target)
    {
        int ans = 0;
        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode *, bool> visited;
        visited[target] = true;

        while (!q.empty())
        {
            bool flag = false;
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();

                if (currNode->left && !visited[currNode->left])
                {
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                    flag = true;
                }

                if (currNode->right && !visited[currNode->right])
                {
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                    flag = true;
                }

                if (parentMap[currNode] && !visited[parentMap[currNode]])
                {
                    q.push(parentMap[currNode]);
                    visited[parentMap[currNode]] = true;
                    flag = true;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }

public:
    int timeToBurnTree(TreeNode *root, int start)
    {
        // your code goes here
        unordered_map<TreeNode *, TreeNode *> parentMap;
        TreeNode *target = bfsToMapParents(root, parentMap, start);
        int ans = findMinTime(root, parentMap, target);
        return ans;
    }
};