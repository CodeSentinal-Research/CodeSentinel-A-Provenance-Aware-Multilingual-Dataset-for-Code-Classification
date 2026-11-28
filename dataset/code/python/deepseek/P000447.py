Here is the Python code:

def find_positions(N, target, arr):
    start = -1
    end = -1

    for i in range(N):
        if arr[i] == target:
            if start == -1:
                start = i
            end = i

    return start, end

def main():
    N = int(input().strip())
    target = int(input().strip())
    arr = list(map(int, input().strip().split()))

    start, end = find_positions(N, target, arr)

    print(start, end)

if __name__ == "__main__":
    main()

This code defines a function `find_positions` that takes the size of the array `N`, the target value `target`, and the array `arr` as input. It initializes `start` and `end` to -1. It then iterates over the array, updating `start` and `end` if the current element is equal to `target`. Finally, it returns the starting and ending index.

The `main` function reads the size of the array `N`, the target value `target`, and the array `arr` from the input. It then calls `find_positions` to get the starting and ending index, and prints them.