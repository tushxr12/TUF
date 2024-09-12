/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
    private:
    int findDiam(TreeNode* root, int &diam)
    {
        if(!root)
            return 0;
        
        int leftHeight = findDiam(root->left, diam);
        int rightHeight = findDiam(root->right, diam);
        diam = max(diam, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    public:
    int diameterOfBinaryTree(TreeNode* root) {
        //your code goes here
        int diam = 0;
        findDiam(root, diam);
        return diam;
    }
};