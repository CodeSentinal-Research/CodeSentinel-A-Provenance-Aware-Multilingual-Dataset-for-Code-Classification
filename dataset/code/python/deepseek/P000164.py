def countTriplets(n, arr, target):
    arr.sort()
    count = 0
    for i in range(n - 2):
        left = i + 1
        right = n - 1
        while left < right:
            if arr[i] + arr[left] + arr[right] == target:
                count += 1
                left += 1
                right -= 1
            elif arr[i] + arr[left] + arr[right] < target:
                left += 1
            else:
                right -= 1
    return count

def main():
    n = int(input().strip())
    target = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(countTriplets(n, arr, target))

if __name__ == "__main__":
    main()