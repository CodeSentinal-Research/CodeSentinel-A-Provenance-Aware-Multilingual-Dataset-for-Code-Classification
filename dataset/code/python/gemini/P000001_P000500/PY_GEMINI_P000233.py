from typing import List

class Solution:
    def maxArea(self, M: List[List[int]], n: int, m: int) -> int:
        def largest_hist(heights):
            stack = []
            max_area = 0
            heights.append(0)
            for i, h in enumerate(heights):
                while stack and heights[stack[-1]] > h:
                    top = stack.pop()
                    w = i if not stack else i - stack[-1] - 1
                    max_area = max(max_area, heights[top] * w)
                stack.append(i)
            heights.pop()
            return max_area

        heights = [0] * m
        max_rect = 0
        for i in range(n):
            for j in range(m):
                heights[j] = heights[j] + 1 if M[i][j] == 1 else 0
            max_rect = max(max_rect, largest_hist(heights))

        return max_rect