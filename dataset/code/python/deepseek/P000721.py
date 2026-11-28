Here's the Python code for the problem:

def find_increasing_subsequences(nums):
    result = []
    path = []
    nums_len = len(nums)

    def backtrack(start):
        if len(path) > 2:
            result.append(path[:])

        for i in range(start, nums_len):
            if len(path) > 0 and path[-1] < nums[i]:
                path.append(nums[i])
                backtrack(i + 1)
                path.pop()

    backtrack(0)
    return result

def main():
    nums = list(map(int, input("Enter the numbers (separated by space): ").split()))
    print("All distinct increasing subsequences: ", find_increasing_subsequences(nums))

if __name__ == "__main__":
    main()

This code first reads the integers from the user separated by space. Then it calls the `find_increasing_subsequences` function with the list of integers as an argument, and prints the result.

The `find_increasing_subsequences` function uses backtracking to find all the distinct increasing subsequences. It starts by adding an empty path, then iterates over the given numbers, and if the last number in the path is smaller than the current number, it adds the current number to the path and recursively calls the `backtrack` function on the next index. If the path has more than two elements, it adds the path to the result and then pops the last element from the path to backtrack.