#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> before(n);
        vector<int> after(n);
        before[0] = 1;
        after[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            before[i] = nums[i - 1] * before[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            after[i] = nums[i + 1] * after[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            answer[i] = before[i] * after[i];
        }

        return answer;
    }
};

int main() {
    Solution s;
    vector<int> a = {1,2,3,4};
    vector<int> ans = s.productExceptSelf(a);
    for (int num : ans) {
        cout<<num<<"\t";        
    }
}
