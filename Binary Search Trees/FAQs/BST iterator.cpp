/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator
{
private:
    stack<TreeNode *> st;

    void pushAll(TreeNode *root)
    {
        for (; root != nullptr; st.push(root), root = root->left)
            ;
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    bool hasNext()
    {
        return !(st.empty());
    }

    int next()
    {
        TreeNode *topNode = st.top();
        st.pop();
        pushAll(topNode->right);
        return topNode->data;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */