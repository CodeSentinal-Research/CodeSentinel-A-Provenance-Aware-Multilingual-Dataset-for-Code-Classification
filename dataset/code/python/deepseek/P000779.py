Here is the Python code for the given problem. The main function reads the input, creates a prefix sum array, and then performs the range sum query efficiently.

def range_sum_query(nums, q):
    prefix_sum = [0] * (len(nums) + 1)
    for i in range(len(nums)):
        prefix_sum[i+1] = prefix_sum[i] + nums[i]
    
    for _ in range(q):
        left, right = map(int, input().split())
        print(prefix_sum[right+1] - prefix_sum[left])

def main():
    n, nums, q = map(int, input().split())
    nums = [int(num) for num in input().split()]
    range_sum_query(nums, q)

if __name__ == "__main__":
    main()

In this code, the `range_sum_query` function takes the list of numbers and the number of queries as input. It first calculates the prefix sum array, and then for each query, it prints the sum of elements between indices left and right (inclusive).

The `main` function reads the number of elements, list of numbers, and the number of queries as input. It calls the `range_sum_query` function to perform the queries.

The `if __name__ == "__main__":` block is used to call the `main` function when the script is run directly.