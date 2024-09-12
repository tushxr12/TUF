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
    int solve(TreeNode* root, int &maxi)
    {
        if(!root)
            return 0;
        
        int leftHeight = max(0,solve(root->left, maxi));
        int rightHeight = max(0,solve(root->right, maxi));
        maxi = max(maxi, leftHeight + rightHeight + root->data);
        return root->data + max(leftHeight, rightHeight);
    }
public:
    int maxPathSum(TreeNode* root) {
        //your code goes here
        if(!root)
            return 0;
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};	