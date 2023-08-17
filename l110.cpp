#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getHeight(TreeNode* root) {
        if (root->left==nullptr&&root->right==nullptr) {
            return 0;
        }
        else if (root->left!=nullptr && root->right!=nullptr) {
            return 1 + max(getHeight(root->left), getHeight(root->right));        
        }
        else if (root->left!=nullptr) {
            return 1 + getHeight(root->left);
        }
        else 
            return 1 + getHeight(root->right);
    
    }

    bool isBalanced(TreeNode* root) {
        if (abs(getHeight(root->left)- getHeight(root->right))>1) {
            return false;            
        }
        int currentHeight = getHeight(root);
        if (currentHeight==1) return true;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}

