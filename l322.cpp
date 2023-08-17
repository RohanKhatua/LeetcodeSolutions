#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //we create a dp array
        //dp[x] tells us the minimum number of coins we need to generate the amount x

        vector<int> dp (amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1;i<=amount;i++) {
            for (int coin : coins) {
                if (i-coin>=0) {
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }

        if (dp[amount]!=INT_MAX) {
            return dp[amount];
        }
        else return -1;
    }

};
