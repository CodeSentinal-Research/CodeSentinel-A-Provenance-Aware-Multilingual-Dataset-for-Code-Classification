Here is a Python solution for the problem:

def recursive_bubble_sort(nums):
    n = len(nums)
    if n == 1:
        return nums
    for i in range(n):
        if i < n - 1 and nums[i] > nums[i + 1]:
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
    return recursive_bubble_sort(nums[:-1]) + [nums[-1]]

def main():
    nums = list(map(int, input().split()))
    nums = recursive_bubble_sort(nums)
    print(' '.join(map(str, nums)))

if __name__ == "__main__":
    main()

In this code, we implement the recursive bubble sort algorithm. The main function reads an integer n followed by n integers from the input, and then prints the sorted array.

Here is how you can run the code:

python3 your_script.py

Replace `your_script.py` with the name of your script.

You can also test the code with the following inputs:

3 2 1 4 5

This will output:

1 2 3 4 5