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


// We return the height of the tree in the dfs function
// The height is 1 + max (height of left subtree, height of right subtree)
// The diameter for any node is 2 + height of left subtree + height of right subtree
// The height of an empty tree is -1
class Solution
{
public:
    int max_dist = 0;
    int dfs(TreeNode * root) {
        if (!root) return -1;

        int left_height = dfs(root->left);
        int right_height = dfs(root->right);

        max_dist = max(max_dist, 2+left_height+right_height);

        int height = 1 + max(left_height, right_height);
        return height;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return max_dist;
    }
};
