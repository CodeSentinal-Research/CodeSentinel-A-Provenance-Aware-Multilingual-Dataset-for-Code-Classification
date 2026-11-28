Here is the Python code with the main function and input handling:

def count_zeros():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    q = int(input().strip())
    for _ in range(q):
        l, r = map(int, input().strip().split())
        print(sum(num == 0 for num in nums[l:r]))

if __name__ == "__main__":
    count_zeros()

In this code, the main function `count_zeros` is defined. It first reads the number of elements `n` and the list of numbers `nums`. Then it reads the number of range queries `q`. For each query, it reads the start and end indices `l` and `r`, and prints the number of zeros in the range `[l, r)`.

This code uses list comprehension to count the number of zeros in each range, and the `sum` function to add up these counts.