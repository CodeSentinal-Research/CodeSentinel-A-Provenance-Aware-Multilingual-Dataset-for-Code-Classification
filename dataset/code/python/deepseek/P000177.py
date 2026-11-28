Here is the Python code:

def find_closest_elements(n, k, target, arr):
    arr.sort()
    left, right = 0, n - k
    while left < right:
        mid = (left + right) // 2
        if target - arr[mid] > arr[mid + k] - target:
            left = mid + 1
        else:
            right = mid
    return arr[left:left + k]

def main():
    n, k = map(int, input().split())
    target = int(input())
    arr = list(map(int, input().split()))
    closest_elements = find_closest_elements(n, k, target, arr)
    print(' '.join(map(str, closest_elements)))

if __name__ == "__main__":
    main()

This code first reads the input, then calls the `find_closest_elements` function with the given inputs, and finally prints the result.