import time
import tracemalloc
from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * n
        
        # Calculate prefix products
        prefix = 1
        for i in range(n):
            res[i] = prefix
            prefix *= nums[i]
        
        # Calculate suffix products and combine with prefix products
        suffix = 1
        for i in range(n-1, -1, -1):
            res[i] *= suffix
            suffix *= nums[i]
        
        return res

# Test data
nums = [i for i in range(100000)]

# Measure running time
start_time = time.time()
solution = Solution()
result = solution.productExceptSelf(nums)
end_time = time.time()

print(f"Running time: {end_time - start_time:.10f} seconds")

# Measure memory consumption
tracemalloc.start()
result = solution.productExceptSelf(nums)
current, peak = tracemalloc.get_traced_memory()
tracemalloc.stop()

print(f"Current memory usage: {current / 10**6:.10f} MB")
print(f"Peak memory usage: {peak / 10**6:.10f} MB")
