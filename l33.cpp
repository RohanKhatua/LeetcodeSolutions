#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size()==1) {
            if (nums[0]==target) return 0;
            else return -1;
        }
        int min_pos = find(nums.begin(), nums.end(), *min_element(nums.begin(), nums.end())) - nums.begin();
        vector<int> sorted_nums;
        if (min_pos != 0)
        {
            for (int i = min_pos; i < min_pos + nums.size(); i++)
            {
                sorted_nums.push_back(nums[i % nums.size()]);
            }
            nums = sorted_nums;
        }

        int low = 0;
        int high = nums.size()-1;

        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                break;
            }

            else if (target < nums[mid])
            {
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        if (ans != -1)
        {
            return (ans + min_pos) % nums.size();
        }
        else
            return -1;
    }
};

int main()
{
    vector<int> v = {1,3};
    Solution s;
    cout << s.search(v, 1);
}
