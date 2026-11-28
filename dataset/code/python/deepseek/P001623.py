def count_prefixes():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    prefix_sums = [arr[0]]
    for i in range(1, N):
        prefix_sums.append(prefix_sums[-1] + arr[i])
    count = 0
    for i in range(N):
        if prefix_sums[i] < 0:
            count += i + 1
    print(count)

count_prefixes()
This code first takes the number of prefixes as input and the array of integers. It then calculates the prefix sum of the array and counts the number of prefixes whose sum is less than zero.