import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        target = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        l, r = 0, n - 1
        idx = -1
        while l <= r:
            # Calculate midpoint to prevent potential overflow
            mid = (l + r) // 2
            if arr[mid] == target:
                idx = mid
                break
            if arr[l] <= arr[mid]:
                if arr[l] <= target < arr[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if arr[mid] < target <= arr[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        print(idx)
if __name__ == '__main__':
    main()