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
    TreeNode *connector(TreeNode *root)
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;

        TreeNode *leftchild = root->left;
        TreeNode *leftMostChildInRight = root->right;

        while (leftMostChildInRight->left)
            leftMostChildInRight = leftMostChildInRight->left;

        leftMostChildInRight->left = leftchild;
        return root->right;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // your code goes here
        if (!root)
            return NULL;

        if (root->data == key)
            return connector(root);

        TreeNode *curr = root;
        while (curr)
        {
            if (curr->data > key)
            {
                if (curr->left && curr->left->data == key)
                {
                    curr->left = connector(root->left);
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->right && curr->right->data == key)
                {
                    curr->right = connector(curr->right);
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};