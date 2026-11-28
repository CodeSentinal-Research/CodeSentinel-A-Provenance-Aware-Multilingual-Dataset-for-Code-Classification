def binary_subarrays(N, Goal, arr):
    count = 0
    left = 0
    total_sum = 0
    for right in range(N):
        total_sum += arr[right]
        while total_sum > Goal:
            total_sum -= arr[left]
            left += 1
        if total_sum == Goal:
            count += right - left + 1
    return count

if __name__ == "__main__":
    N, Goal = map(int, input().split())
    arr = list(map(int, input().split()))
    print(binary_subarrays(N, Goal, arr))