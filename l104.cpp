#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// The height of a node is 1 + max(height of its left child, height of its right child)
// The height of an empty tree is -1
class Solution
{
public:
    int height (TreeNode * root) {
        if (!root) return -1;
        return 1 + max(height(root->left), height(root->right));
    }

    int maxDepth(TreeNode *root)
    {
        return 1 + height(root);
    }
};
