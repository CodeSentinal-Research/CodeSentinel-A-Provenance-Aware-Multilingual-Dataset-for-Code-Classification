# problem title : Remove Duplicate Letters
# Solve the stated task using standard input and standard output.
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last = {c: i for i, c in enumerate(s)}
        stack = []
        seen = set()

        for i, c in enumerate(s):
            if c not in seen:
                while stack and stack[-1] > c and i < last[stack[-1]]:
                    seen.remove(stack.pop())
                seen.add(c)
                stack.append(c)

        return "".join(stack)
