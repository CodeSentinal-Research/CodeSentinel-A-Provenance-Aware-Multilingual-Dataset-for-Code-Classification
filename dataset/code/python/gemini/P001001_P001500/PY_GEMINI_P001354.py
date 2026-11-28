from typing import List

class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        res = []

        def backtrack(idx: int):
            if idx == len(num) and len(res) >= 3:
                return True
            for i in range(idx + 1, len(num) + 1):
                part = num[idx:i]
                if part[0] == '0' and len(part) > 1:
                    break
                val = int(part)
                if val >= 2**31:
                    break

                if len(res) >= 2:
                    if val < res[-1] + res[-2]:
                        continue
                    elif val > res[-1] + res[-2]:
                        break

                res.append(val)
                if backtrack(i):
                    return True
                res.pop()

            return False

        backtrack(0)
        return res