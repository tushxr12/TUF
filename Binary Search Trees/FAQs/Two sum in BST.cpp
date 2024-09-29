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
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

public:
    bool twoSumBST(TreeNode *root, int k)
    {
        // your code goes here
        vector<int> v;
        inorder(root, v);
        int i = 0, j = v.size() - 1;

        while (i < j)
        {
            int sum = v[i] + v[j];
            if (sum == k)
                return true;
            else if (sum > k)
                j--;
            else
                i++;
        }
        return false;
    }
};