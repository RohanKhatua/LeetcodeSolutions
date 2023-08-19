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

class Solution
{
public:
    vector<int> traversal;

    void inorderTraversal(TreeNode * root) {
        if (root->left) inorderTraversal(root->left);
        traversal.push_back(root->val);
        if (root->right) inorderTraversal(root->right);
    }

    bool isValidBST(TreeNode *root)
    {     

        inorderTraversal(root);
        for (int i=0;i<traversal.size()-1;i++) {
            if (traversal[i]>traversal[i+1]) return false;
        }
        return true;

    }
};
