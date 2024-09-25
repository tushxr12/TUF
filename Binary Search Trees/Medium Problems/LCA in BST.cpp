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
    TreeNode *lca(TreeNode *root, int p, int q)
    {
        // your code goes here
        if (!root || root->data == p || root->data == q)
            return root;

        TreeNode *left = lca(root->left, p, q);
        TreeNode *right = lca(root->right, p, q);
        if (left && right)
            return root;

        return (left != nullptr) ? left : right;
    }
};