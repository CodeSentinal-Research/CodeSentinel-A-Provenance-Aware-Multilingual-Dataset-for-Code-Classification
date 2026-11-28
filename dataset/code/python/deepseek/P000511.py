def nextGreaterElements(nums):
    n = len(nums)
    ans = [-1] * n
    stack = []

    for i in range(n * 2 - 1):
        while stack and nums[stack[-1]] < nums[i % n]:
            j = stack.pop()
            ans[j] = nums[i % n]
        stack.append(i % n)

    return ans

def main():
    n = int(input("Enter the number of elements: "))
    nums = list(map(int, input("Enter the elements: ").split()))

    result = nextGreaterElements(nums)

    print(result)

if __name__ == "__main__":
    main()