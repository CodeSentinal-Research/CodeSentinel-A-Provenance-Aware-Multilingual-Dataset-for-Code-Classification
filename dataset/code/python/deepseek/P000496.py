def sum_of_minimums(arr):
    n = len(arr)
    prefix = [0]*(n+1)
    for i in range(n):
        prefix[i+1] = min(prefix[i], arr[i])

    suffix = [0]*(n+1)
    for i in range(n-1, -1, -1):
        suffix[i] = min(suffix[i+1], arr[i])

    total = 0
    for i in range(n):
        total = (total + min(prefix[i], suffix[i+1])) % (10**9 + 7)

    return total

def main():
    arr = [int(x) for x in input().split()]
    print(sum_of_minimums(arr))

if __name__ == "__main__":
    main()