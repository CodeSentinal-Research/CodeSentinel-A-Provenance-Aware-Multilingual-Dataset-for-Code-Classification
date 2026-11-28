Here is the Python code:

def remove_duplicates(nums):
    if not nums:
        return 0

    i = 0
    for j in range(1, len(nums)):
        if nums[j] != nums[i]:
            i += 1
            nums[i] = nums[j]

    return i + 1

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    length = remove_duplicates(nums)
    print(length)

if __name__ == "__main__":
    main()

In this code, we use two pointers `i` and `j` to traverse the sorted array. `i` is the slow-runner and `j` is the fast-runner. As long as `nums[j]` is different from `nums[i]`, we increment `i` and assign `nums[j]` to `nums[i]`.

The `main` function is the entry point of the program, it reads the input data, calls the `remove_duplicates` function and prints the result.

Please note that the input is taken from the standard input (stdin), and the output is printed to the standard output (stdout).