# problem title : Backspace String Compare
# Solve the stated task using standard input and standard output.
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def build(string: str) -> str:
            res = []
            for c in string:
                if c != '#':
                    res.append(c)
                elif res:
                    res.pop()
            return "".join(res)

        return build(s) == build(t)
