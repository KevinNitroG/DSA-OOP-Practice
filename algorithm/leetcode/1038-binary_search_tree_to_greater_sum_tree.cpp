// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    TreeNode *bstToGst(TreeNode *root)
    {
        TreeNode *temp = new TreeNode(0);
        util(root, temp);
        delete temp;
        return root;
    }
    TreeNode *util(TreeNode *root, TreeNode *temp = nullptr)
    {
        if (!root)
            return temp;
        TreeNode *right = util(root->right, temp);
        root->val += right->val;
        temp->val = root->val;
        temp = util(root->left, temp);
        return temp;
    }
};
