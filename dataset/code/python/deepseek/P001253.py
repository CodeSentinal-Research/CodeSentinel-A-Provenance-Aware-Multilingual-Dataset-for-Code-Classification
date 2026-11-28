def min_abs_diff_pairs(arr):
    arr.sort()
    min_diff = float('inf')
    pairs = []
    for i in range(1, len(arr)):
        diff = abs(arr[i] - arr[i-1])
        if diff < min_diff:
            min_diff = diff
            pairs = [(arr[i-1], arr[i])]
        elif diff == min_diff:
            pairs.append((arr[i-1], arr[i]))
    return pairs

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    pairs = min_abs_diff_pairs(arr)
    for pair in pairs:
        print(pair)

if __name__ == "__main__":
    main()