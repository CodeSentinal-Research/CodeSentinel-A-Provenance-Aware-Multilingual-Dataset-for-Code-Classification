def find_element(arr, target):
    for i in range(len(arr)):
        if arr[i] < target:
            return i
    return -1

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    X = int(input())

    result = find_element(arr, X)

    print(result)

if __name__ == "__main__":
    main()