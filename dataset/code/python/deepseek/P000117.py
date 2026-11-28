Here is the Python code for the given problem:

def check_duplicate(arr):
    arr.sort()
    for i in range(len(arr) - 1):
        if arr[i] == arr[i + 1]:
            return "Yes"
    return "No"

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    print(check_duplicate(arr))

if __name__ == "__main__":
    main()
This program first reads the size of the array and the elements of the array. It then sorts the array and checks if adjacent elements are the same. If so, it returns "Yes", otherwise it returns "No".