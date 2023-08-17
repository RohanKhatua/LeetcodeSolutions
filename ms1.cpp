#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> &A, vector<int> &B)
{
    // create an adjacency matrix where each edge is A[i] to B[i]
    vector<int> els;
    vector<vector<int>> adj(n, els);
    for (int i = 0; i < A.size(); i++)
    {
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
    }

    int ans = 0;
    vector<bool> done(n,false);
    while (true)
    {
        vector<vector<int>> adj_copy = adj;
        bool check = false;

        // for every vertex check the length of its adjacency list
        for (int i = 0; i <= n - 1; i++)
        {
            if (adj[i].size() <= 1 && !done[i])
            {
                done[i] = true;
                check = true;
                // remove the vertex from every list
                //  for (auto lst : adj)
                //  {
                //      int loc = find(lst.begin(), lst.end(), i) - lst.begin();
                //      if (loc>=0&&loc<lst.size()) {
                //          lst.erase(loc+lst.begin());
                //      }
                //  }

                if (adj[i].size() == 1)
                {
                    int neighbour = adj[i][0];
                    auto loc = find(adj_copy[neighbour].begin(), adj_copy[neighbour].end(), i);
                    adj_copy[neighbour].erase(loc);
                }
            }
        }

        adj = adj_copy;
        if (check)
            ans++;
        else
            break;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> a = {0, 1, 2};
    vector<int> b = {1, 2, 0};
    cout << solution(4, a, b);
    return 0;
}
