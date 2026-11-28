def longest_prefix():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    prefix_sum = [0] * (N + 1)
    for i in range(N):
        prefix_sum[i+1] = prefix_sum[i] + arr[i]
    
    left, right = 0, N
    while left < right:
        mid = (left + right + 1) // 2
        if prefix_sum[mid] >= 0:
            left = mid
        else:
            right = mid - 1
    
    if left == 0:
        print('0')
    else:
        print(left)

longest_prefix()