#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    vector<vector<int>> res;

    void dfs(int i, vector<int> &curr, int total, int target, vector<int> &candidates) {
        if (total==target) {
            vector<int> copy = curr;
            res.push_back(copy);
            return;
        }

        if (total>target || i>=candidates.size()) {
            return;
        }

        curr.push_back(candidates[i]);
        dfs(i, curr, total+candidates[i],target, candidates);
        curr.erase(curr.end()-1);
        dfs(i+1, curr, total, target, candidates);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(0, vector<int>() = {}, 0, target, candidates);
    }
};
