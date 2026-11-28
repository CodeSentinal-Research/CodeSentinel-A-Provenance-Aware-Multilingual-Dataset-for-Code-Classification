# problem title : Longest Palindrome by Concatenating Two-Letter Words
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        count = Counter(words)
        ans = 0
        has_middle = False

        for w, cnt in count.items():
            if w[0] == w[1]:
                ans += (cnt // 2) * 4
                if cnt % 2 == 1:
                    has_middle = True
            elif w[0] < w[1]:
                rev = w[::-1]
                ans += min(cnt, count[rev]) * 4

        return ans + (2 if has_middle else 0)
