class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n = len(t)
        m = len(s)

        if n > m:
            return ""
        if n == m:
            if t == s:
                return t
            else:
                return ""
        
        left = 0
        right = 0

        for i in range(m):
            # if the current character is not in t
            if s[i] not in t:
                # we move the left pointer only 
                #if we don't want the first letter of the window
                if s[left] not in t:
                    left += 1
                right += 1
            else:
                # the current character is in t
                right += 1

                # now check if l can be pulled forward
                if s[i] == s[left] and i!=left:
                    # l can be pulled up
                    curr = left+1
                    while s[curr] not in t:
                        curr += 1

                    left = curr
        

        return s[left:right]


s = Solution()
print(s.minWindow("ADOBECODEBANC", "ABC")) # BANC