def count_frequency():
    N = int(input().strip())
    target = int(input().strip())
    arr = list(map(int, input().strip().split()))
    frequency = arr.count(target)
    print(frequency)