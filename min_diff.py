from typing import List
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) <= 4:
            return 0
        else:
            nums.sort()
            movesMade = 0
            l = 0
            r = len(nums)-1
            while movesMade <=3:
                leftJump = nums[l+1] - nums[l]
                rightJump = nums[r] - nums[r-1]

                if leftJump >= rightJump:
                    l += 1
                else:
                    r+=1
                movesMade+=1
            return nums[r]-nums[l]

s = Solution()
print(s.minDifference([3, 100, 20]))