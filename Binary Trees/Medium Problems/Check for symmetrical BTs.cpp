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
    bool checkIfSymmetric(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 || !root2)
            return (root1 == root2);

        if (root1->data != root2->data)
            return false;

        return (checkIfSymmetric(root1->left, root2->right) && checkIfSymmetric(root1->right, root2->left));
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        // your code goes here
        return (root == NULL || checkIfSymmetric(root->left, root->right));
    }
};