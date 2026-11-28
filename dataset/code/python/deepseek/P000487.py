Here is the Python code:

def trap(height):
    if not height:
        return 0

    left, right = 0, len(height) - 1
    max_left, max_right = 0, 0
    res = 0

    while left < right:
        if height[left] < height[right]:
            if height[left] > max_left:
                max_left = height[left]
            else:
                res += max_left - height[left]
            left += 1
        else:
            if height[right] > max_right:
                max_right = height[right]
            else:
                res += max_right - height[right]
            right -= 1

    return res

if __name__ == "__main__":
    heights = [0,1,0,2,1,0,1,3,2,1,2]
    print(trap(heights))  

In this code, we use two pointers (left and right) to represent the start and end of the array, and keep track of the maximum height to the left and right. If the current height is less than the maximum height to the left, we can calculate how much water can be trapped between the current bar and the left bar. If the current height is greater than the maximum height to the left, we update the maximum height to the left. Similar process is done for the right bar.