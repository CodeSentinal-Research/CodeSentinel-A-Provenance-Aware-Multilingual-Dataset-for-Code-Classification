from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        words = set(wordDict)
        memo = {}

        def dfs(string: str) -> List[str]:
            if not string:
                return [""]
            if string in memo:
                return memo[string]

            res = []
            for w in words:
                if string.startswith(w):
                    sub = dfs(string[len(w):])
                    for sentence in sub:
                        res.append(w + (" " + sentence if sentence else ""))

            memo[string] = res
            return res

        return dfs(s)