#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void dfs(vector<vector<int>> &image, int i, int j, int current_color, int target_color, int r, int c, vector<vector<bool>> visited) {
        //check if current cell is within boundaries or not
        // and if it matches the previous cell that we came here from
        //current_color nevcer changes as we only want to access cells of the src color

        // cout<<image[0][0]<<endl;

        if (i<0 || i>=r || j<0 || j>=c||visited[i][j]||image[i][j]!=current_color) {
            return;
        }
        image[i][j]= target_color;
        visited[i][j] = true;
        dfs(image, i-1, j, current_color, target_color, r,c,visited);
        dfs(image, i+1, j, current_color, target_color, r,c, visited);
        dfs(image, i, j-1, current_color, target_color, r,c, visited);
        dfs(image, i, j+1, current_color, target_color, r,c, visited);
        

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        vector<vector<bool>> visited (r, vector<bool>(c, false));

        // visited[sr][sc]=true;

        //src cell is already at thre target color, return matrix as it is
        //if we try to flood fill from this position we will only reach cells that are already the target color
        if (image[sr][sc] ==color) return image;
        dfs(image, sr, sc, image[sr][sc], color, r, c, visited);
        return image;

    }
};

int main() {
    Solution obj;
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    int sr = 1;
    int sc =1;
    int color = 2;
    obj.floodFill(image, sr, sc, color);
    for (int i = 0;i<image.size();i++) {
        for (int j=0;j<image[0].size();j++) {
            cout<<image[i][j]<<"\t";
        }
        cout<<endl;
    }
    
}