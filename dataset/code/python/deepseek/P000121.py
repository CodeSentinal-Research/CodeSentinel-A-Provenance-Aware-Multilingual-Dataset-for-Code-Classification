def findMajorityElement():
    n = int(input())
    arr = list(map(int, input().split()))
    
    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    
    for key, value in freq.items():
        if value > n//2:
            return key

    return None