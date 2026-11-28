def second_smallest(arr):
    arr.sort()
    for i in range(1, len(arr)):
        if arr[i] != arr[0] and arr[i] != arr[i-1]:
            return arr[i]
    return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(second_smallest(arr))

main()