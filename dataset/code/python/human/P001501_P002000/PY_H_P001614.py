class Solution:

    def kadane(self, arr):
        curr = best = arr[0]

        for x in arr[1:]:
            curr = max(x, curr + x)
            best = max(best, curr)

        return best

    def maximumSumRectangle(self, R, C, M):

        ans = float('-inf')

        for left in range(C):

            temp = [0] * R

            for right in range(left, C):

                for row in range(R):
                    temp[row] += M[row][right]

                ans = max(ans, self.kadane(temp))

        return ans