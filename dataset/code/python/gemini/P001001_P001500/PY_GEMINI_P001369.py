from typing import List

class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        left_rem = right_rem = 0
        for c in s:
            if c == '(':
                left_rem += 1
            elif c == ')':
                if left_rem > 0:
                    left_rem -= 1
                else:
                    right_rem += 1

        res = set()

        def backtrack(idx: int, open_c: int, close_c: int, l_rem: int, r_rem: int, cur: List[str]):
            if idx == len(s):
                if l_rem == 0 and r_rem == 0:
                    res.add("".join(cur))
                return

            c = s[idx]
            if c == '(' and l_rem > 0:
                backtrack(idx + 1, open_c, close_c, l_rem - 1, r_rem, cur)
            elif c == ')' and r_rem > 0:
                backtrack(idx + 1, open_c, close_c, l_rem, r_rem - 1, cur)

            cur.append(c)
            if c != '(' and c != ')':
                backtrack(idx + 1, open_c, close_c, l_rem, r_rem, cur)
            elif c == '(':
                backtrack(idx + 1, open_c + 1, close_c, l_rem, r_rem, cur)
            elif close_c < open_c:
                backtrack(idx + 1, open_c, close_c + 1, l_rem, r_rem, cur)
            cur.pop()

        backtrack(0, 0, 0, left_rem, right_rem, [])
        return list(res)