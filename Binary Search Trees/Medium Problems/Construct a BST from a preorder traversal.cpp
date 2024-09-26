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
    TreeNode *build(vector<int> &preorder, int &i, int bound)
    {
        if (i == preorder.size() || preorder[i] > bound)
            return NULL;

        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->data);
        root->right = build(preorder, i, bound);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        // your code goes here
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};