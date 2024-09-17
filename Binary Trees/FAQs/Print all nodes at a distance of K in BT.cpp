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
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &trackParent)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                trackParent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right)
            {
                trackParent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // your code goes here
        unordered_map<TreeNode *, TreeNode *> trackParent;
        markParents(root, trackParent);
        vector<int> ans;
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;

        while (!q.empty())
        {
            int size = q.size();
            if (currLevel++ == k)
                break;

            for (int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();

                if (currNode->left && !visited[currNode->left])
                {
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }
                if (currNode->right && !visited[currNode->right])
                {
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                }
                if (trackParent[currNode] && !visited[trackParent[currNode]])
                {
                    q.push(trackParent[currNode]);
                    visited[trackParent[currNode]] = true;
                }
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        return ans;
    }
};