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
    bool check(TreeNode *root, long long minVal, long long maxVal)
    {
        if (!root)
            return true;

        if (root->data >= maxVal || root->data <= minVal)
        {
            return false;
        }

        bool leftCheck = check(root->left, minVal, root->data);
        bool rightCheck = check(root->right, root->data, maxVal);

        return (leftCheck && rightCheck);
    }

public:
    bool isBST(TreeNode *root)
    {
        // your code goes here
        return check(root, (long long)INT_MIN, (long long)INT_MAX);
    }
};