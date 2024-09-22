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
    vector<int> floorCeilOfBST(TreeNode *root, int key)
    {
        int floor = -1;
        int ceil = -1;

        TreeNode *current = root;
        while (current)
        {
            if (current->data == key)
            {
                floor = current->data;
                break;
            }
            else if (current->data < key)
            {
                floor = current->data;
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        current = root;
        while (current)
        {
            if (current->data == key)
            {
                ceil = current->data;
                break;
            }
            else if (current->data > key)
            {
                ceil = current->data;
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        return {floor, ceil};
    }
};