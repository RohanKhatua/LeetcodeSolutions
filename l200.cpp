#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int i, int j, set<pair<int, int>> &visited, vector<vector<char>> &grid, int m, int n)
    {
        queue<pair<int, int>> q;
        visited.insert(make_pair(i, j));
        q.push(make_pair(i, j));

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop(); // Remove the front element from the queue

            vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto dir : dirs)
            {
                pair<int, int> new_loc = {row + dir.first, col + dir.second};
                if (new_loc.first >= 0 && new_loc.first < m && new_loc.second >= 0 && new_loc.second < n &&
                    grid[new_loc.first][new_loc.second] == '1' && visited.find(new_loc) == visited.end())
                {
                    q.push(new_loc);
                    visited.insert(new_loc);
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0 || n == 0)
            return 0;

        set<pair<int, int>> visited;
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    if (visited.find(make_pair(i, j)) == visited.end())
                    {
                        bfs(i, j, visited, grid, m, n);
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << s.numIslands(grid);
}
