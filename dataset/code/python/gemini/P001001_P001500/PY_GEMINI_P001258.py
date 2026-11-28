class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last = {c: i for i, c in enumerate(s)}
        stack = []
        seen = set()

        for i, c in enumerate(s):
            if c not in seen:
                # Maintain monotonic stack property by popping smaller elements
                while stack and stack[-1] > c and i < last[stack[-1]]:
                    seen.remove(stack.pop())
                seen.add(c)
                stack.append(c)

        return "".join(stack)