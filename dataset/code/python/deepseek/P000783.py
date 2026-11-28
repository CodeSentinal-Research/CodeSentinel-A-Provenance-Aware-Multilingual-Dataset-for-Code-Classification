def count_even(n, nums, q):
    count = [0 for _ in range(n + 1)]

    for i in range(1, n + 1):
        count[i] += count[i - 1]
        if nums[i - 1] % 2 == 0:
            count[i] += 1

    for L, R in q:
        print(count[R] - count[L - 1])


n = int(input())
nums = list(map(int, input().split()))
q = [list(map(int, input().split())) for _ in range(int(input()))]

count_even(n, nums, q)