def search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    target = int(input())
    result = search(arr, target)
    print(result)

if __name__ == "__main__":
    main()