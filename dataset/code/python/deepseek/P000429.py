def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    target = int(input().strip())
    result = linear_search(arr, target)
    print(result)

if __name__ == "__main__":
    main()