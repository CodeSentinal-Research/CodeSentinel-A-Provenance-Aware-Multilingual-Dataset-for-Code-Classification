Here is the Python code:

def solve():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))

    count = 0
    for i in range(n):
        if arr[i] > arr[0]:
            count += 1

    print(count)

if __name__ == "__main__":
    solve()
This code first reads the number of elements (`n`) and the elements themselves (`arr`). Then it iterates over the array and increments the count whenever it finds a node with a greater value than the root. The count is then printed.