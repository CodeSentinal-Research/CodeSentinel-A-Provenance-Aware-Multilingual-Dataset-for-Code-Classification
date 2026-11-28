def count_windows():
    N, K, X = map(int, input().split())
    arr = list(map(int, input().split()))
    
    count = 0
    for i in range(N - K + 1):
        if sum(arr[i:i+K]) > X:
            count += 1
            
    print(count)

count_windows()