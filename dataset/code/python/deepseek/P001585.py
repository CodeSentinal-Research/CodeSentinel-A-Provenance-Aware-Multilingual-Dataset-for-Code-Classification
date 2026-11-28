def maxFrequency(N, K, arr):
    arr.sort()
    maxFreq = 1
    currFreq = 1
    for i in range(1, N):
        if arr[i] == arr[i-1]:
            currFreq += 1
            maxFreq = max(maxFreq, currFreq)
        else:
            currFreq = 1
    return maxFreq

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(maxFrequency(N, K, arr))

if __name__ == "__main__":
    main()