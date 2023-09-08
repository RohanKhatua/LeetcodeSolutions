#include <bits/stdc++.h>
using namespace std;

// TLE Approach
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int res = 0;
//         for (int i=0;i<height.size();i++) {            
//             if (height[i]>0) {
                
//                 // try to find a bounding wall for this
//                 for (int curr_height = height[i];curr_height>0;curr_height--) {
//                     int j = i + 1;
//                     while (j<height.size()) {
//                         if (height[j]>=curr_height) {
//                             res+=j-i-1;
//                             break;
//                         }
//                         j++;
//                     }
//                 }
//             }
//         }

//         return res;
//     }
// };

// Every position can store water based on its left and right bounding walls 
// The height of the block wastes space that could be used to store water so we subtract the height at each position
// 2 pointer approach
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 0) {
            return 0;
        }

        int left = 0;
        int right = height.size() - 1;

        int lmax = height[left];
        int rmax = height[right];

        int res = 0;

        while (left<right) {
            if (lmax<rmax) {
                left++;
                lmax = max(lmax, height[left]);
                res += lmax - height[left]; // here lmax is greater than or equal to height[left] so need to check for negative
            }
            else {
                right--;
                rmax = max(rmax, height[right]);
                res += rmax - height[right]; // // here rmax is greater than or equal to height[right] so need to check for negative
            }
        }

        return res;
    }
};

int main () {
    Solution s;
    cout << s.trap(vector<int>() = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
}
