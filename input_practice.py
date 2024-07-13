# 2 3
# 1 2 3
# 4 5 6

r, c = [int(dim) for dim in input().split()]

matrix = []

for i in range(r):
    matrix.append([int(x) for x in input().split()])
    
# input taken

def max_path_sum(grid, r, c):
    if not grid or not grid[0]:
        return 0
    
    dp = [[[0, 0] for _ in range(c)] for _ in range(r)]
    
    dp[0][0][0] = grid[0][0]
    dp[0][0][1] = grid[0][0] * 2
    
    # the dp array stores a tuple for every position
    # tuple [0] stores maximum path value until that point with no doubling
    # tuple [1] stores maximum path value with doubling
    
    for i in range(r):
        for j in range(c):
            if i == 0 and j==0:
                continue
            
            from_top = dp[i-1][j][0] if i > 0 else 0
            from_left = dp[i][j-1][0] if j > 0 else 0
            
            dp[i][j][0] = max(from_top, from_left) + grid[i][j]
            
            # so we store the value without doubling now
            
            # best from previous with already doubled
            from_top_doubled = dp[i-1][j][1] if i > 0 else 0
            from_left_doubled = dp[i][j-1][1] if j > 0 else 0
            
            best_with_doubled = max(from_top_doubled, from_left_doubled)
            
            # best with doubled contains values where doubling has already been done
            
            if i > 0:
                from_top = dp[i-1][j][0] + grid[i][j]*2
                
            if j > 0:
                from_left = dp[i][j-1][0] + grid[i][j]*2
                
            # from top and from left now contains values if we decide to double this one
            
            # so now we can choose
            # we already have chosen the value for no previous doubling and no current doubling
            # that is stored in dp[i][j][0]
            
            # for dp[i][j][1] we choose between current doubling + prev or previous doubling + curr
            dp[i][j][1] = max(best_with_doubled + grid[i][j], from_top, from_left)
            
    return dp[r-1][c-1][1]

print(max_path_sum(matrix, r, c))
            
    