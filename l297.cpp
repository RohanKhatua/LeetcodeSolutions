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

class Codec
{
    vector<string> str_tokenizer(string s, char delimit)
    {
        stringstream ss(s);
        string word;
        vector<string> res;

        while (!ss.eof())
        {
            getline(ss, word, delimit);
            res.push_back(word);
        }

        return res;
    }

public:
    //preorder dfs
    void dfs(TreeNode *node, vector<string> &res)
    {
        if (!node)
        {
            res.push_back("N");
            return;
            //if null no need to look at its left and right child
        }
        //Root left right
        res.push_back(to_string(node->val));
        dfs(node->left, res);
        dfs(node->right, res);
    }

    TreeNode *dfs(vector<string> &vals, int &i)
    {
        if (vals[i] == "N")
        {
            i++;
            return nullptr;
            //if null we do not need to make a new node
        }

        //if not null then we make the node
        TreeNode *node = new TreeNode(stoi(vals[i]));
        i++;
        //make left subtree first, then right
        node->left = dfs(vals, i);
        node->right = dfs(vals, i);

        return node;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        vector<string> res;
        dfs(root, res);

        string s;

        for (string val : res)
        {
            s += val + ",";
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> vals = str_tokenizer(data, ',');
        int i = 0;

        return dfs(vals, i);
    }
};
