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
    vector <int> bottomView(TreeNode *root){
    	//your code goes here
      if(!root)
        return {};
      map<int,int> mpp;
      queue<pair<TreeNode* ,pair<int,int>>> q;
      q.push({root, {0,0}});

      while(!q.empty())
      {
        auto i = q.front(); // i = root , {0,0}
        q.pop();
        auto node = i.first;
        int line = i.second.first;
        int level = i.second.second;
        mpp[line] = node->data;
        if(node->left)
          q.push({node->left, {line - 1,level + 1}});
        if(node->right)
          q.push({node->right, {line + 1, level + 1}});
      }
      vector<int> ans;
      for(auto i : mpp)
        ans.push_back(i.second);
      return ans;
    }
};