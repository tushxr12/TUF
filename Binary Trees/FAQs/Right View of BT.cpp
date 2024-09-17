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
    void reversePreOrder(TreeNode *node, int level, vector<int> &ans)
    {
        if (!node)
            return;

        if (level == ans.size())
            ans.push_back(node->data);

        reversePreOrder(node->right, level + 1, ans);
        reversePreOrder(node->left, level + 1, ans);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        // your code goes here
        vector<int> ans;
        int level = 0;
        reversePreOrder(root, level, ans);
        return ans;
    }
};