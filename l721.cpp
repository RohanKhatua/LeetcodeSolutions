#include <bits/stdc++.h>
using namespace std;

// Accounts are to be merged if they contain at least one common email
// This is a Union Find Problem
// Also used in leetcode 547 - number of provinces

class UnionFind
{
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }

        rank = vector<int>(n, 1);
    }

    int find_leader(int n1)
    {
        int res = n1;
        while (res != parent[res])
        {
            parent[res] = parent[parent[res]]; // path compression
            res = parent[res];
        }

        return res;
    }

    int get_union(int n1, int n2)
    {
        int p1 = find_leader(n1);
        int p2 = find_leader(n2);

        if (p1 == p2)
        {
            return 0; // union not performed
        }

        else
        {
            // group with p1 has more elements
            // so elements in group 2 should also point to group with p1
            if (rank[p1] > rank[p2])
            {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else
            {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }

            return 1;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        UnionFind uf = UnionFind(accounts.size());

        unordered_map<string, int> emailToAcc;

        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                if (emailToAcc.find(email) != emailToAcc.end())
                {
                    // email already in map
                    //  then account at index i and account at index emailToAcc[email] belong to the same person

                    uf.get_union(i, emailToAcc[email]);

                    // merge the two accounts
                }
                else
                {
                    // email not in map
                    emailToAcc[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> emailGroup;

        for (auto pr : emailToAcc)
        {
            string email = pr.first;
            int index = pr.second;

            int leader = uf.find_leader(index);

            emailGroup[leader].push_back(email);
        }

        vector<vector<string>> res;

        for (auto pr : emailGroup)
        {
            string name = accounts[pr.first][0];
            vector<string> curr;
            curr.push_back(name);
            sort(emailGroup[pr.first].begin(), emailGroup[pr.first].end());
            for (string email : emailGroup[pr.first])
            {
                curr.push_back(email);
            }

            res.push_back(curr);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> v = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                {"John", "johnsmith@mail.com", "john00@mail.com"},
                                {"Mary", "mary@mail.com"},
                                {"John", "johnnybravo@mail.com"}};

    s.accountsMerge(v);
}
