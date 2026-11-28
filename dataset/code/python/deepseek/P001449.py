def largest_integer(arr):
    arr = set(arr)
    for i in range(200001, -1, -1):
        if -i in arr:
            return i
    return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(largest_integer(arr))

main()