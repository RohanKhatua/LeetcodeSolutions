#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int ans = 0;
        int fresh = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                if (grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty() && fresh > 0)
        {
            int queue_len = q.size();
            for (int i = 0; i < queue_len; i++)
            {
                
                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                for (auto dir : dirs)
                {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if (row < 0 || row == rows || col < 0 || col == cols || grid[row][col] != 1)
                    {
                        continue;
                    }

                    grid[row][col] = 2;
                    q.push(make_pair(row, col));
                    fresh--;
                }
            }

            ans++;
        }

        return (fresh == 0 ? ans : -1);
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{2,1,1},{1,1,1},{0,1,2}};

    cout<<s.orangesRotting(v);
}