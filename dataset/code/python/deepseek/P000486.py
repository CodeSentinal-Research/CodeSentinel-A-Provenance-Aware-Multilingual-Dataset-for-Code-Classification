def largestRectangleArea(heights):
    stack = []
    maxArea = 0
    for i in range(len(heights)):
        while stack and (heights[i] < heights[stack[-1]]):
            h = heights[stack.pop()]
            w = i if not stack else i - stack[-1]
            maxArea = max(maxArea, h * w)
        stack.append(i)
    
    return maxArea

def main():
    heights = [int(i) for i in input().split()]
    print(largestRectangleArea(heights))

if __name__ == "__main__":
    main()

In this code, we use a stack to store indices. The stack will store the indices of the bars that are smaller than the current bar (or the bars on the top of the stack). Each time we find a bar that is smaller than the top of the stack, we pop the top bar from the stack and calculate the area of the rectangle.

We also need to consider the case when the current bar is smaller than the top of the stack. In this case, we calculate the area for the rectangle as the current index and the top of the stack.

Finally, we return the maximum area found.

The main function reads the heights of the bars from the input and prints the maximum area of the rectangle.