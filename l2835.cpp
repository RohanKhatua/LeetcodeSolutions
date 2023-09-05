#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int target)
    {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[log2(num)] ++;
        }

        int ops = 0;     
        int rem = target;   

        for (auto pr : freq) {
            int num = pow(2, pr.first);
            while (num<=rem && freq[pr.first]>=0 && rem>0) {
                rem-=num;
                freq[pr.first]--;
            }
            if (rem==0) break;
        }


    }
};
