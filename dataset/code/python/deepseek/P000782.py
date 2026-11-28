Here is the Python code to solve the problem.

def count_in_range(n, nums, q):
    prefix_sums = [0] * (n + 1)
    for i in range(n):
        prefix_sums[i + 1] = prefix_sums[i] + nums[i]

    for _ in range(q):
        l, r = map(int, input().split())
        print(prefix_sums[r + 1] - prefix_sums[l])

def main():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    q = int(input().strip())
    count_in_range(n, nums, q)

if __name__ == "__main__":
    main()

In this code, the main function first reads the number of elements (n), the array of integers (nums), and the number of queries (q). It then calls the count_in_range function.

The count_in_range function first calculates the prefix sums of the array, which are stored in the prefix_sums list. Then, for each query, it reads the indices l and r, and prints the difference between the prefix sum at r + 1 and the prefix sum at l.

Please note that you need to run this code in a local environment or online Python compilers to run it.