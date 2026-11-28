from typing import List

class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        res = [0] * (2 * n - 1)
        used = [False] * (n + 1)

        def backtrack(idx: int) -> bool:
            while idx < len(res) and res[idx] != 0:
                idx += 1
            if idx == len(res):
                return True

            for num in range(n, 0, -1):
                if used[num]:
                    continue
                if num == 1:
                    res[idx] = 1
                    used[1] = True
                    if backtrack(idx + 1):
                        return True
                    res[idx] = 0
                    used[1] = False
                elif idx + num < len(res) and res[idx + num] == 0:
                    res[idx] = num
                    res[idx + num] = num
                    used[num] = True
                    if backtrack(idx + 1):
                        return True
                    res[idx] = 0
                    res[idx + num] = 0
                    used[num] = False

            return False

        backtrack(0)
        return res