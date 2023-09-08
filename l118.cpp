#include <bits/stdc++.h>
using namespace std;

class Solution
{
public: 
    
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        
        for (int i=1;i<numRows;i++) {
            vector<int> curr;
            for (int j=0;j<=i;j++) {
                if (j==0 || j==i) curr.push_back(1);
                else {
                    curr.push_back(ans[i-1][j] + ans[i-1][j-1]);
                }
            }

            ans[i] = curr;
        }

        // ans.erase(ans.begin());
        return ans;
    }
};

int main() {
    int n = 5;
    Solution s;
    vector<vector<int>> res = s.generate(n);

    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout<<res[i][j]<<" ";
        }

        cout<<endl;
    }
}
