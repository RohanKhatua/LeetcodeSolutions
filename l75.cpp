#include <bits/stdc++.h>
using namespace std;


// The array should have all the 0s together, then the 1s, then the 2s
// We can use bukcet sort as there are only 3 values
// class Solution
// {
// public:
//     void sortColors(vector<int> &nums)
//     {
//         int freq[3] = {0};
//         for (int i=0;i<nums.size();i++) {
//             freq[nums[i]]++;
//         }
//         int index = 0;
//         for (int i=0;i<3;i++) {
//             for (int j=0;j<freq[i];j++) {
//                 nums[index] = i;
//                 index++;
//             }
//         }
//     }
// };

// QuickSort Partitioning Solution
// We have a left and right pointer
// if the ith number is 0, we swap it with left pointer and move left pointer ahead and increment i
// if the ith number is 2, we swap it with right pointer and move the pointer back, we do not increment i
// We do not increment i because if the right pointer at that time was at 0 then we basically brought a 0 to the middle of the array
// By not incrementing i, we allow the left pointer to again swap with the 0 and then take it back to the left of the array
// The array is sorted when i exceeds the right pointer as everything to the right of it is already 2, so no more swapping is necessary
class Solution
{
public:

    void sortColors(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int i = 0;

        while (i<=right) {
            if (nums[i]==0) {
                swap(nums[left], nums[i]);
                left++;
                i++;
            }

            else if (nums[i]==2) {
                swap(nums[right], nums[i]);
                right--;
            }

            else {
                i++;
            }
        }
    }
};

int main () {
    Solution s;
    vector<int> v = {2, 0, 2, 1, 1, 0};
    s.sortColors(v);
    for (int x : v) {
        cout<<x<<" ";
    }
}
