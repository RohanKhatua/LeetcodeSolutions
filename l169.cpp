#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int majorityElement(vector<int> &nums)
//     {
//         unordered_map<int, int> mp;
//         int half = nums.size()/2;
//         for (int num : nums) {
//             mp[num]++;
//             if (mp[num]>half) {
//                 return num;
//             }
//         }
//     }
// };

// Moore Voting Algo

class Solution {
public:
    int majorityElement (vector<int> &nums) {
        int res = nums[0];
        int count = 1;

        for (int i=1;i<nums.size();i++) {
            if (nums[i]!=res) {
                count--;
                if (count == -1) {
                    count = 0;
                    res = nums[i];
                }
            }

            else count ++;
        }

        return res;
    }
};

int main() {
    Solution s;
    cout<<s.majorityElement(vector<int> () = {2,2,1,1,1,2,2});
}


