#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        // characters remaining = s.length() - i
        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (string word : wordDict)
            {
                int len = word.length();
                if (s.length() - i >= len)
                {
                    string sub = s.substr(i, len);
                    if (sub == word && dp[i+len])
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[0];
    }
};

int main() {
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};

    Solution sol;
    cout << sol.wordBreak(s, dict);
}