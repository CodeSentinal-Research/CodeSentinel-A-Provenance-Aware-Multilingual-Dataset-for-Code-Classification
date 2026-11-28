from typing import List

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []

        def backtrack(idx: int, dots: int, cur: str):
            if dots == 4 and idx == len(s):
                res.append(cur[:-1])
                return
            if dots > 4:
                return

            for l in range(1, 4):
                if idx + l <= len(s):
                    part = s[idx:idx + l]
                    if (part[0] != '0' or l == 1) and int(part) <= 255:
                        backtrack(idx + l, dots + 1, cur + part + ".")

        backtrack(0, 0, "")
        return res