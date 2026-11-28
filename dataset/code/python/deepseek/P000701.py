def findMin(nums):
    if len(nums) == 1:
        return nums[0]
    mid = len(nums) // 2
    left_min = findMin(nums[:mid])
    right_min = findMin(nums[mid:])
    return min(left_min, right_min)

def main():
    nums = list(map(int, input().split()))[1:]
    print(findMin(nums))

if __name__ == "__main__":
    main()
This Python program uses recursion to find the minimum element in an array. The `findMin` function splits the array into two halves and recursively finds the minimum element in each half. If the array has only one element, it returns that element as the minimum.

The `main` function reads the input array of integers from the user, calls the `findMin` function with this array, and prints the result.

The complexity of this program is O(log n) because we divide the array into two halves in each recursive call, and we perform a constant number of operations for each call.