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
    void addLeftBoundaryWithoutLeafs(TreeNode *root, vector<int> &ans)
    {
        TreeNode *currNode = root->left;
        while (currNode)
        {
            if (!isLeaf(currNode))
            {
                ans.push_back(currNode->data);
            }
            if (currNode->left)
            {
                currNode = currNode->left;
            }
            else
            {
                currNode = currNode->right;
            }
        }
    }

    void addRightBoundaryWithoutLeafs(TreeNode *root, vector<int> &ans)
    {
        TreeNode *currNode = root->right;
        vector<int> temp;
        while (currNode)
        {
            if (!isLeaf(currNode))
            {
                temp.push_back(currNode->data);
            }
            if (currNode->right)
                currNode = currNode->right;
            else
                currNode = currNode->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            ans.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode *root, vector<int> &ans)
    {
        if (isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        if (root->left)
            addLeaves(root->left, ans);
        if (root->right)
            addLeaves(root->right, ans);
    }

    bool isLeaf(TreeNode *root)
    {
        return !root->left && !root->right;
    }

public:
    vector<int> boundary(TreeNode *root)
    {
        // your code goes here
        vector<int> ans;
        if (!root)
            return ans;
        if (!isLeaf(root))
            ans.push_back(root->data);
        addLeftBoundaryWithoutLeafs(root, ans);
        addLeaves(root, ans);
        addRightBoundaryWithoutLeafs(root, ans);
        return ans;
    }
};