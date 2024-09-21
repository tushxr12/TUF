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
public:
    vector<int> getInorder(TreeNode* root) {
    	//your code goes here
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr)
        {
            if(!curr->left)
            {
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                TreeNode* currsLeft = curr->left;
                while(currsLeft->right && currsLeft->right != curr)
                {
                    currsLeft = currsLeft->right;
                }

                //Thread is not there, make a thread
                if(currsLeft->right == NULL)
                {
                    currsLeft->right = curr;
                    curr = curr->left;
                }
                else //Thread is already there, remove it and move to right
                {
                    currsLeft->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};