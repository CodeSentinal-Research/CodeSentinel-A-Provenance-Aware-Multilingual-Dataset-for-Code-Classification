Sure, here is the Python code with main function and input handling.

def maximum_width_ramp(nums):
    stack = []
    res = 0
    for i, num in enumerate(nums):
        if not stack or nums[stack[-1]] > num:
            stack.append(i)
    for i in range(len(nums) - 1, -1, -1):
        while stack and nums[stack[-1]] >= nums[i]:
            j = stack.pop()
            if stack:
                res = max(res, j - stack[-1])
    return res


def main():
    nums = [5, 5, 3, 8, 6, 2, 6, 4, 6, 10]
    print(maximum_width_ramp(nums))


if __name__ == "__main__":
    main()

In this code, we use a stack to keep track of the indices of numbers that are less than or equal to the current number. When a number is larger, we pop out the indices from the stack and calculate the width (j - i), update the maximum width, and continue popping out the indices until the current number is larger again.