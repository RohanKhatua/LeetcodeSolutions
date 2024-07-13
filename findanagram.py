from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        # for every position check the required number of letters
        # if that letter itself is in the word
        # we slide the window
        # we find the first position and then keep moving forward
        # if we remove a letter and add the same one back we again have an anagram

        if len(p) > len(s):
            return []
        
        target = {}

        for letter in p:
            if not target.get(letter):
                target[letter] = 1
            else:
                target[letter] += 1

        curr_freq = {}

        l = 0
        r = len(p)-1

        # initialise curr_freq

        for i in range(l, r+1):
            if not curr_freq.get(s[i]):
                curr_freq[s[i]] = 1
            else:
                curr_freq[s[i]] += 1

        res = []

        while True:
            if curr_freq == target:
                res.append(l)
            
            if r == len(s)-1:
                break
            
            # if not the end of the string update curr_freq
            # remove left most character
            # add character after the rightmost one
            curr_freq[s[l]] -= 1
            if curr_freq[s[l]] == 0:
                del curr_freq[s[l]]
            
            if not curr_freq.get(s[r+1]):
                curr_freq[s[r+1]] = 1
            else:
                curr_freq[s[r+1]] += 1

            l+=1
            r+=1

        return res

s = Solution()

print(s.findAnagrams("cbaebabacd", "abc")) # [0, 6]