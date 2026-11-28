def predict_the_winner():
    n = int(input())
    arr = list(map(int, input().split()))
    prefix_sum = [0] * (n + 1)
    suffix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + arr[i]
        suffix_sum[n - i] = suffix_sum[n - i + 1] + arr[n - i - 1]
    for i in range(1, n + 1):
        if prefix_sum[i] == suffix_sum[i]:
            return "YES"
    return "NO"

print(predict_the_winner())

This Python code is for the problem. It first reads the input for the number of elements and the array. It then calculates the prefix and suffix sums of the array. It then checks if the prefix sum and suffix sum are equal at each element, and if they are, returns "YES", otherwise it returns "NO".