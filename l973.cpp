#include <bits/stdc++.h>
using namespace std;

class Compare {
    public:
    bool operator()(vector<int> p1, vector<int> p2) {
        int dist1 = p1[0]*p1[0] + p1[1]*p1[1];
        int dist2 = p2[0]*p2[0] + p2[1]*p2[1];
        return dist1>dist2;
    }
};

class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>, Compare> pq;
        for (int i=0;i<points.size();i++) {
            pq.push(points[i]);
        }
        vector<vector<int>> closest;
        for (int i=0;i<k;i++){
            closest.push_back(pq.top());
            pq.pop();
        }
        return closest;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {{2,2}, {5,3}, {1,1}};
    int k =2;
    Solution s;
    vector<vector<int>> ans = s.kClosest(v, k);
    for (auto point : ans) {
        cout<<point[0]<<","<<point[1]<<endl;
    }
    return 0;
}

