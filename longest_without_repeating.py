class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        res = ""
        curr = ""
        i = 0
        while i < len(s):
            if s[i] not in curr:
                curr+=s[i]
                i += 1
            else:
                # find the last index of the repeating character
                # slice the string from the beginning to the current position-1
                # find the rightmost index 

                sliced = s[:i]
                right_index = sliced.rindex(s[i])                
                i = right_index + 1

                if len(curr) > len(res):
                    res = curr
                curr = ""

        return max(len(res), len(curr))

s = Solution()
print(s.lengthOfLongestSubstring("aab")) # 3