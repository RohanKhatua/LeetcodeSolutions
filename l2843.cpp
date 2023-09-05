#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumPossibleSum(int n, int target)
    {
        int curr_len = 0;
        // vector<int> not_allowed;
        unordered_map<int, bool> mp;
        int sum = 0;
        int i = 1;

        while (curr_len<n) {
            if (!mp[i]){
                curr_len++;
                sum+=i;
                mp[target-i] = true;
            }
            i++;
        }

        return sum;
    }
};

int main() {
    Solution s;
    int n = 2;
    int target = 3;

    cout<<s.minimumPossibleSum(n, target);
}
