from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0 for i in range(n)] for j in range(n)]
        # 2d array of zeroes

        for i in range(n):
            dp[i][i] = nums[i]

        # the sum between ith and ith index is nums[i]

        for arr_len in range(1, n):
            for i in range(0, n-arr_len):
                # dp[i][i+arr_len] = max(dp[i][i+arr_len-1] + dp[i+arr_len][i+arr_len], dp[i][i+arr_len-1], dp[i+arr_len][i+arr_len])
                dp[i][i+arr_len] = max(dp[i][i+arr_len-1] + nums[i+arr_len], dp[i+arr_len][i+arr_len], dp[i][i+arr_len-1])

        return dp[0][n-1]

s = Solution()
print(s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4])) # 6