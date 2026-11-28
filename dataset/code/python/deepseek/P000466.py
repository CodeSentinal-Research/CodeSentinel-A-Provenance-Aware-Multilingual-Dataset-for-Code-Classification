Here is the Python code for the problem:

def find_triplet(N, target):
    arr = list(map(int, input().split()))
    arr.sort()
    for i in range(N - 2):
        start = i + 1
        end = N - 1
        while start < end:
            if arr[i] + arr[start] + arr[end] == target:
                print("Yes")
                return
            elif arr[i] + arr[start] + arr[end] < target:
                start += 1
            else:
                end -= 1
    print("No")

def main():
    N, target = map(int, input().split())
    find_triplet(N, target)

if __name__ == "__main__":
    main()

This code first reads N and target, then reads a sorted array. It then iterates over the array, for each element, it finds the pair which sums up to the target sum. If it finds a pair, it prints "Yes" and stops. If it doesn't find any pair, it prints "No".