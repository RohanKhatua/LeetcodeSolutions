#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        int len = nums.size();
        if (len==1) {
           return {nums};
        }
        for (int i=0;i<len;i++) {
            int n = nums[0];
            nums.erase(nums.begin());

            auto perms = permute(nums);

            for (auto perm : perms) {
                perm.push_back(n);   
                res.push_back(perm);             
            }

            // for (auto perm : perms) {
            //     res.push_back(perm);
            // }
            nums.push_back(n);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,2,3};
    vector<vector<int>> res = s.permute(v);
    for (auto perm : res) {
        for (auto ele : perm) {
            cout<<ele<<" ";            
        }
        cout<<endl;
    }
}
