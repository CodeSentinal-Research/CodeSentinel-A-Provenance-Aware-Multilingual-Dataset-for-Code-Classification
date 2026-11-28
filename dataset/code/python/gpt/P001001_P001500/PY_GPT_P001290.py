# problem title : Maximum Score from Removing Stones
# Solve the stated task using standard input and standard output.
class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        arr = sorted([a, b, c])
        if arr[0] + arr[1] <= arr[2]:
            return arr[0] + arr[1]
        return sum(arr) // 2
