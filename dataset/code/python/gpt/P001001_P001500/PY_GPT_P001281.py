# problem title : Remove K Digits
# Solve the stated task using standard input and standard output.
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for digit in num:
            while k > 0 and stack and stack[-1] > digit:
                stack.pop()
                k -= 1
            stack.append(digit)

        final_stack = stack[:-k] if k else stack
        ans = "".join(final_stack).lstrip('0')
        return ans if ans else "0"
