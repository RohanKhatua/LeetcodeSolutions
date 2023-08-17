#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int crs, set<int> &visited, unordered_map<int, vector<int>> &preMap) {
        if (visited.find(crs)!=visited.end()) {
            return false;
        }
        if (preMap[crs].empty()) {
            return true;
        }
        visited.insert(crs);
        for (auto pre:preMap[crs]) {
            if (!dfs(pre, visited, preMap)) {
                return false;
            }
        }
        visited.erase(crs);
        preMap[crs] ={};
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        for (auto pre : prerequisites) {
            preMap[pre[0]].push_back(pre[1]);
        }

        set<int> visited;
        for (int i=0;i<numCourses;i++) {
            if (!dfs(i, visited, preMap)) return false;
        }
        return true;
    }
    
};

int main() {
    Solution s;
    vector<vector<int>> v = {{2,1}, {1,0}};
    cout<<s.canFinish(3, v);
}
