#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffixMax(n,0);
        //set the last element manually
        suffixMax[n-1] = prices[n-1];
        //suffixMax[i] = largest element including and to the right of the ith index
        for (int i=n-2;i>=0;i--) {
            suffixMax[i] = max(suffixMax[i+1], prices[i]);
        }

        int profit = 0;
        for (int i=0;i<n;i++) {
            profit = max(profit, suffixMax[i]-prices[i]);
        }

        return profit;

    }
};

int main (){
    Solution obj;
    vector<int> v = {2,4,1};
    obj.maxProfit(v);
}
