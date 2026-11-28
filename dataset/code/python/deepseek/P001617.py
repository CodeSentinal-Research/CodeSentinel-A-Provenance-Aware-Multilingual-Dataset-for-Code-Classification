Here is the Python code to solve the problem:

def count_even_sum_prefixes():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))

    prefix_sum = [0] * (N + 1)
    for i in range(N):
        prefix_sum[i + 1] = prefix_sum[i] + arr[i]

    count = 0
    for i in range(1, N + 1):
        if prefix_sum[i] % 2 == 0:
            count += 1

    print(count)


def main():
    count_even_sum_prefixes()


if __name__ == "__main__":
    main()

This code first reads the number of elements `N` and the array of integers. It then calculates the prefix sum of the array, and counts the number of prefixes whose sum is even. Finally, it prints the count.