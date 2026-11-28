Here is the Python code:

def findMiddleIndex(nums):
    left_sum = 0
    right_sum = sum(nums)
    for i, num in enumerate(nums):
        right_sum -= num
        if left_sum == right_sum:
            return i
        left_sum += num
    return -1

This function iterates over the array, and for each element, it subtracts the current element from the right sum and adds it to the left sum. If the left sum equals the right sum, it means we have found the middle index.

Here is the main function:

def main():
    nums = list(map(int, input("Enter numbers separated by space: ").strip().split()))
    print(findMiddleIndex(nums))

if __name__ == "__main__":
    main()

This program first takes input from the user, which is a space-separated sequence of numbers. It then calls the `findMiddleIndex` function with these numbers, and prints the result.