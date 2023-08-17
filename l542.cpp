#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        if (i==m||j==n||j<0||i<0) 
            return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //we have to do a bfs
        vector<vector<int>> moves = {{1,0},{0,1},{0,-1},{-1,0}};
        queue<pair<int, int>> q;
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dis (m, vector<int>(n,-1));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (mat[i][j]==0) {
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            pair <int,int> current = q.front();
            q.pop();
            for (auto x : moves) {
                int i = current.first + x[0];
                int j = current.second + x[1];

                if (isValid(i,j,m,n)&&dis[i][j]==-1) {
                    q.push({i,j});
                    dis[i][j] = dis[current.first][current.second]+1;
                }
            }
        }

        return dis;
        
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{0,0,0}, {0,1,0}, {1,1,1}};
    mat = s.updateMatrix(mat);
    for (auto v : mat) {
        for (auto el : v) {
            cout<<el<<"\t";
        }
        cout<<endl;
    }
}
