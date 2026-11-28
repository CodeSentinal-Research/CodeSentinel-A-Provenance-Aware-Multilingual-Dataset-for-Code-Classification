Here is a simple Python code that implements the solution:

def count_prefixes(n, arr):
    prefix_sum = [0] * n
    prefix_sum[0] = arr[0]
    for i in range(1, n):
        prefix_sum[i] = prefix_sum[i-1] + arr[i]
    count = 0
    for i in range(n):
        if prefix_sum[i] > 0:
            count += 1
    return count

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(count_prefixes(n, arr))

if __name__ == "__main__":
    main()

In this code, we first read the number of integers `n` from the first line of the input, then read the integers themselves from the second line. The `count_prefixes` function then computes the prefix sums of the array, and finally counts the number of prefixes that have a sum greater than zero. The `main` function handles the input and output.