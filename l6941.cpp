#include <bits/stdc++.h>
using namespace std;

//is wrong check answer

class Solution
{
    public:
    int minimumOperations(vector<int> &nums)
    {
        vector<int> group_counts(3, 0);
        vector<int> target_positions(3, 0);

        for (int num : nums)
        {
            group_counts[num - 1]++;
        }

        int total_ops = nums.size();

        for (int i = 0; i < 3; ++i)
        {
            target_positions[i] = total_ops;
            total_ops -= group_counts[i];
        }

        return *min_element(target_positions.begin(), target_positions.end());
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 3, 1, 2};

    cout << s.minimumOperations(v);
}