#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
// We keep moving to the parent of the node till it becomes a parent of itself 
// i.e. we find the parent of the group
    static int find_leader (vector<int> &parent, int n) {
        int res = n;
        while (res!=parent[res]) {
            parent[res] = parent[parent[res]]; // path compression
            res = parent[res]; // moving res to parent
        }

        return res;
    }

// Returns 1 if a union was performed and 0 if not
    static int get_union (int n1, int n2, vector<int> &parent, vector<int> &rank) {
        int p1 = find_leader(parent, n1);
        int p2 = find_leader(parent, n2);

        // If both n1 and n2 have the same parent then they are already in the same group
        if (p1==p2) return 0;

        // We add the elements to the larger group
        // The size of the component each node belongs to is given in rank 
        if (rank[p2] > rank[p1]) {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        else {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }

        return 1;
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int num_cities = isConnected[0].size();
        vector<int> parent;
        for (int i=0;i<num_cities;i++) {
            parent.push_back(i);
        }

        vector<int> rank(num_cities, 1);
        vector<pair<int, int>> edges;

        // We get a list of edges 
        for (int i = 0;i<num_cities;i++) {
            for (int j=i;j<num_cities;j++) {
                if (isConnected[i][j]==1) {
                    edges.push_back({i, j});
                }
            }
        }

        int res = num_cities;

        for (auto edge : edges) {
            res -= get_union(edge.first, edge.second, parent, rank);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> v = {{1,1,0},{1,1,0}, {0,0,1}};
    Solution s;
    cout<<s.findCircleNum(v);
}
