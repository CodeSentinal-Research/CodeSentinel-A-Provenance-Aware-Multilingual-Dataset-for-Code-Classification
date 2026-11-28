def count_odd_numbers(nums, queries):
    pre_sums = [0]
    for num in nums:
        pre_sums.append(pre_sums[-1] + num % 2)

    for L, R in queries:
        print(pre_sums[R+1] - pre_sums[L])

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    q = int(input())
    queries = [tuple(map(int, input().split())) for _ in range(q)]
    count_odd_numbers(nums, queries)

if __name__ == "__main__":
    main()

In this Python code, the function `count_odd_numbers` first calculates the prefix sum of odd and even numbers in the input list `nums`. Then, for each query `(L, R)`, it calculates the count of odd numbers between `L` and `R` and prints this count.

The `main` function is the entry point of the program. It first reads the number of elements `n` and the elements of the list `nums`. It then reads the number of queries `q` and the queries themselves. The `count_odd_numbers` function is then called with these inputs.

The `if __name__ == "__main__":` line ensures that this file is executed only if it is run directly, not if it is imported as a module in another file.