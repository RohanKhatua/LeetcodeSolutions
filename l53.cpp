#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = INT_MIN;
        int max_el = INT_MIN;
        int current_sum=0;
        // int current_sum = 0;
        // for (int i=0;i<nums.size();i++) {
        //     current_sum+=nums[i];

        //     if (current_sum>max_sum) {
        //          max_sum = current_sum;
        //      }

        //      if (current_sum<0) {
        //          current_sum = 0;
        //     }
        // }

        for (int i=0;i<nums.size();i++) {
            max_el = max(max_el, nums[i]);
            if (nums[i]<0) {
                current_sum = 0;
            }

            else {
                current_sum += nums[i];
                max_sum = max(max_sum, current_sum);
            }
        }

        if (max_el<0) {
            return max_el;
        }
        else return max_sum;



        
        
    }
};

int main()
{
    Solution s;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(v);
}