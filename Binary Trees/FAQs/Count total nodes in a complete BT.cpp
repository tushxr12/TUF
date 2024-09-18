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
    void inorder(TreeNode *root, int &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans++;
        inorder(root->right, ans);
    }

public:
    int countNodes(TreeNode *root)
    {
        // your code goes here
        int ans = 0;
        inorder(root, ans);
        return ans;
    }
};