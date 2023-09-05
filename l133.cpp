#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    /*
        the function checks whether the node sent to it has already been copied
        if it has, then we simply return the copy that has been created
        if it has not been cloned yet
        create a clone
        and for every neighbour of the node, recursively clone it and then its neighbours
        we return a copy of the node sent to the function
    */
    Node *dfs(Node *node, unordered_map<Node *, Node *> oldToNew)
    {
        if (find(oldToNew.begin(), oldToNew.end(), node) != oldToNew.end())
        {
            return oldToNew[node];
        }
        Node *copy = new Node(node->val);
        oldToNew[node] = copy;

        for (auto n : node->neighbors)
        {
            copy->neighbors.push_back(dfs(n, oldToNew));
        }

        return copy;
    }

    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> oldtoNew;
        if (node == nullptr)
            return {};
        else
            return dfs(node, oldtoNew);
    }
};

int main()
{
}
