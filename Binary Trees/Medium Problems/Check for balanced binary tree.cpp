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
    int check(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = check(root->left);
        if (left == -1)
            return -1;
        int right = check(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        // your code goes here
        return (check(root) != -1);
    }
};