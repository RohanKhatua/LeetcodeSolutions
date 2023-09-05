#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> res;

    map<int, vector<int>> contentMap;

    void getContents(TreeNode *root)
    {
        if (contentMap.find(root->val)!=contentMap.end()) {
            for (int ele : contentMap[root->val]) {
                res.push_back(ele);
            }
            return;
        }
        // if (root==nullptr) return;
        res.push_back(root->val);
        if (root->left != nullptr)
            getContents(root->left);
        if (root->right != nullptr)
            getContents(root->right);
        contentMap[root->val] = res;
        return;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
    //     if (root->val == p->val || root->val == q->val)
    //     {
    //         return root;
    //     }
    //     res.clear();
    //     if (root->left != nullptr)
    //     {
    //         getContents(root->left);
    //         if (find(res.begin(), res.end(), p->val) != res.end())
    //         {
    //             // p is on the left of the tree
    //             if (find(res.begin(), res.end(), q->val) == res.end())
    //             {
    //                 // q is not on the left, so it is on the right
    //                 return root;
    //             }
    //             else
    //             {
    //                 // p is on the left q is also on the left
    //                 return lowestCommonAncestor(root->left, p, q);
    //             }
    //         }
    //         else
    //         {
    //             // p is on the right of the tree
    //             if (find(res.begin(), res.end(), q->val) != res.end())
    //             {
    //                 // q is on the left of the tree
    //                 return root;
    //             }
    //             else
    //             {
    //                 // p and q are on the right of the tree
    //                 return lowestCommonAncestor(root->right, p, q);
    //             }
    //         }
    //     }
    //     else
    //     {
    //         // root does not have left child
    //         // both children have to be on the right
    //         return lowestCommonAncestor(root->right, p, q);
    //     }

        if (root==nullptr || root->val == p->val || root->val == q->val) {
            return root;
        } 

        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p, q);

        if (left==nullptr) {
            return right;
        }

        else if (right==nullptr) {
            return left;
        }

        else return root;
    }
};