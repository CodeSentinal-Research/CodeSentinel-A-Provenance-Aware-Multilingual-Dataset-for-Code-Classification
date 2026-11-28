def max_sweetness(N, K, sweetness):
    start, end = min(sweetness), sum(sweetness)
    while start < end:
        mid = (start + end) // 2
        if check(mid, K, sweetness):
            start = mid + 1
        else:
            end = mid
    return start - 1

def check(target, k, sweetness):
    pieces = 1
    total = 0
    for s in sweetness:
        if total + s <= target:
            total += s
        else:
            total = s
            pieces += 1
            if pieces > k:
                return False
    return True

def main():
    N, K = map(int, input().split())
    sweetness = list(map(int, input().split()))
    print(max_sweetness(N, K, sweetness))

if __name__ == "__main__":
    main()