#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   
    int countPairs(vector<int> &nums, int target)
    {
        int ans = 0;
        for (int i=0;i<nums.size();i++) {
            for (int j=i+1;j<nums.size();j++) {
                if (nums[i]+nums[j]<target) ans++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-1, 1, 2, 3, 1};
    int target = 2;

    cout<<s.countPairs(v, target);
}

