Here is the Python code:

def remove_duplicates(arr):
    if not arr:
        return 0

    slow = 1
    for fast in range(1, len(arr)):
        if arr[fast] != arr[fast-1]:
            arr[slow] = arr[fast]
            slow += 1

    return slow

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))

    new_len = remove_duplicates(arr)

    print(new_len)
    print(' '.join(map(str, arr[:new_len])))

if __name__ == "__main__":
    main()

This code works by using two pointers, one at the start (`slow`) and one at the end (`fast`). `fast` starts from the second element and moves through the array. If the current element is not the same as the previous one, it's copied to `slow` and `slow` is incremented. At the end, `slow` is the length of the array without duplicates.