from typing import List


class Solution:

    visited = []

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:

        init_color = image[sr][sc]
        image[sr][sc] = color
        self.visited.append((sr, sc))
        
        # up
        if sr>0 and image[sr-1][sc] == init_color and (sr-1, sc) not in self.visited:
            self.floodFill(image, sr-1, sc, color)
            # image[sr-1][sc] = color
        # left
        if sc>0 and image[sr][sc-1] == init_color and (sr, sc-1) not in self.visited:
            self.floodFill(image, sr, sc-1, color)
            # image[sr][sc-1] = color
        # down
        if sr < len(image)-1 and image[sr+1][sc] == init_color and (sr+1, sc) not in self.visited:
            self.floodFill(image, sr+1, sc, color)
            # image[sr+1][sc] = color
        # right
        if sc < len(image[0])-1 and image[sr][sc+1] == init_color and (sr, sc+1) not in self.visited:
            self.floodFill(image, sr, sc+1, color)
            # image[sr][sc+1] = color

        return image
        
image = [[1,1,1],[1,1,0],[1,0,1]]
color = 2
sr = 1
sc = 1

sol = Solution()
print(sol.floodFill(image, sr, sc, color))