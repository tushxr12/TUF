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
    void traverse(TreeNode *node, int key, int &predecessor, int &successor)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->data < key)
        {
            predecessor = max(predecessor, node->data);
            traverse(node->right, key, predecessor, successor);
        }
        else if (node->data > key)
        {
            successor = min(successor, node->data);
            traverse(node->left, key, predecessor, successor);
        }
        else
        {
            if (node->left != nullptr)
            {
                TreeNode *temp = node->left;
                while (temp->right != nullptr)
                {
                    temp = temp->right;
                }
                predecessor = temp->data;
            }

            if (node->right != nullptr)
            {
                TreeNode *temp = node->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                successor = temp->data;
            }
        }
    }

public:
    vector<int> succPredBST(TreeNode *root, int key)
    {
        int predecessor = -1;
        int successor = numeric_limits<int>::max();

        traverse(root, key, predecessor, successor);
        return {predecessor == -1 ? -1 : predecessor, successor == numeric_limits<int>::max() ? -1 : successor};
    }
};