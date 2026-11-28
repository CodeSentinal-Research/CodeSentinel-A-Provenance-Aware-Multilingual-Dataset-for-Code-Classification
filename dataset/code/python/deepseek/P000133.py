def rearrange_array(n, arr):
    arr.sort()
    result = []
    left = 0
    right = n - 1

    while left < right:
        result.append(arr[right])
        result.append(arr[left])
        left += 1
        right -= 1
    if left == right:
        result.append(arr[left])

    return result

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    print(rearrange_array(n, arr))

if __name__ == "__main__":
    main()