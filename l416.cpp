#include <bits/stdc++.h>
using namespace std;


// Decision tree solution - TLE
class Solution1
{
public:
    // Each subset has a half of the total sum
    // The problem reduces to finding a subset with sum equal to half the total sum
    // Make a decision tree for choosing or not choosing an element

    // Check if the remaining elements are large enough to reach the target sum

    bool decisionTree (vector<int> &nums, int target, int index) {
        if (target == 0) return true;
        if (target < 0) return false;
        if (index == nums.size()) return false;
        return decisionTree(nums, target - nums[index], index + 1) || decisionTree(nums, target, index + 1);
    }

    bool canPartition(vector<int> &nums)
    {
        int target = 0;
        for (int num : nums) {
            target+=num;
        }

        if (target%2!=0) return false;

        return decisionTree(nums, target/2, 0);
    }
};

// Dynamic Programming Solution

class Solution2
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum%2!=0) return false;

        int target = sum/2;
        int n = nums.size();

        vector<vector<bool>> dp (n+1, vector<bool>(target + 1, false));
        // a matrix which has n+1 rows, target + 1 columns all initialized to false
        // We can set dp[0...n][0] = true -> always possible to get a subset with sum 0 just don't include anything

        for (int i = 0;i<=n;i++) {
            dp[i][0] = true;
        }

        // Now we fill the rest of the DP matrix

        for (int i=1;i<=n;i++) {
            for (int j=1;j<=target;j++) {
                // j is the target for this cell
                // if the current number is less than the target
                int curr_number = nums[i-1];
                if (curr_number<=j) {
                    // We now have two choices, either include it or not
                    // if we include it the target drops to j - curr_number
                    // otherwise the target stays at j
                    // if either of those allows for an answer then we can assign true to this cell 
                    // We refer to the previously calculated results
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-curr_number];
                }
                else {
                    //the curr_number exceeds the required target, we have to reject it
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
    }
};

// Single dimension DP solution
class Solution3 {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum%2!=0) {
            return false;
        }

        unordered_set<int> dp;
        dp.insert(0);

        int target = sum/2;

        for (int i = nums.size()-1;i>=0;i--) {
            unordered_set<int> nextDp;
            for (int t : dp) {
                if (t + nums[i] == target) {
                    return true;
                }
                nextDp.insert(t + nums[i]);
                nextDp.insert(t);
            }

            dp = nextDp;
        }

        if (dp.find(target)!=dp.end()) return true;
        else return false;


    }
};

int main() {
    Solution3 s;
    cout << s.canPartition(vector<int> () = {1, 5, 11, 5});
}
