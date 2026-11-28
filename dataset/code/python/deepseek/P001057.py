def max_distinct_elements(N, K, arr):
    arr.sort()
    distinct_elements = set(arr)
    return min(len(distinct_elements), N-K)

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(max_distinct_elements(N, K, arr))

if __name__ == "__main__":
    main()