# problem title : Expression Add Operators
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []

        def backtrack(idx: int, path: str, eval_val: int, mult_val: int):
            if idx == len(num):
                if eval_val == target:
                    res.append(path)
                return

            for i in range(idx + 1, len(num) + 1):
                part = num[idx:i]
                if part[0] == '0' and len(part) > 1:
                    break
                val = int(part)

                if idx == 0:
                    backtrack(i, part, val, val)
                else:
                    backtrack(i, path + "+" + part, eval_val + val, val)
                    backtrack(i, path + "-" + part, eval_val - val, -val)
                    backtrack(i, path + "*" + part, eval_val - mult_val + mult_val * val, mult_val * val)

        backtrack(0, "", 0, 0)
        return res
