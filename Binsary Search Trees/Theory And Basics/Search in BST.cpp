/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // your code goes here
        while (root && root->data != val)
            root = (val > root->data) ? root->right : root->left;
        return root;
    }
};