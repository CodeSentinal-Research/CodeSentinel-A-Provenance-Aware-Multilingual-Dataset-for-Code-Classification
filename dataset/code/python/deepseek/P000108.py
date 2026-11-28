def check_descending():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    if all(arr[i] >= arr[i + 1] for i in range(len(arr) - 1)):
        print("Sorted")
    else:
        print("Not Sorted")

if __name__ == "__main__":
    check_descending()