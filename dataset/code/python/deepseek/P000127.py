Here is a Python code snippet that uses two pointers technique to find the maximum water container.

def maxArea(height):
    l, r = 0, len(height) - 1
    max_area = 0
    while l < r:
        max_area = max(max_area, min(height[l], height[r]) * (r - l))
        if height[l] < height[r]:
            l += 1
        else:
            r -= 1
    return max_area

def main():
    n = int(input())
    height = list(map(int, input().split()))
    print(maxArea(height))

if __name__ == "__main__":
    main()

In this code, we start by initializing two pointers `l` and `r` to the two ends of the input list. We then enter a loop where we calculate the area between the two lines and update our maximum area if necessary. If the line with smaller height is on the left, we increment the left pointer `l`. Otherwise, if the line with smaller height is on the right, we decrement the right pointer `r`. We continue this process until `l` and `r` cross each other, which means we've found the maximum container.