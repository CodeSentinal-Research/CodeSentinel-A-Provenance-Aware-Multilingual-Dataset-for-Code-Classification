Here's a Python solution that uses the two-pointer technique:

def maxArea(height):
    max_area = 0
    l = 0
    r = len(height) - 1

    while l < r:
        max_area = max(max_area, min(height[l], height[r]) * (r - l))

        if height[l] < height[r]:
            l += 1
        else:
            r -= 1

    return max_area

This code works by maintaining two pointers, `l` and `r`, initially at the start and end of the list respectively. The maximum area is initialized to 0.

The code then enters a loop where it calculates the area between the lines at `l` and `r` and compares it to the current maximum area. The shorter line (either `l` or `r`) is moved if the shorter line is shorter than the other line.

The time complexity of this solution is O(N), where N is the length of the height list.

The code can be used for input handling as follows:

def main():
    n = int(input().strip())
    height = list(map(int, input().strip().split()))
    print(maxArea(height))

if __name__ == "__main__":
    main()

This code first reads the number of elements, and then the elements themselves. It then calls the `maxArea` function with the input and prints the result.