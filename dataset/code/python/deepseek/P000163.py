def find_triplet(n, target, arr):
    arr.sort()
    for i in range(0, n-2):
        start = i + 1
        end = n - 1
        while start < end:
            if arr[i] + arr[start] + arr[end] == target:
                return "Yes"
            elif arr[i] + arr[start] + arr[end] < target:
                start += 1
            else:  
                end -= 1
    return "No"

def main():
    n, target = map(int, input().split())
    arr = list(map(int, input().split()))
    print(find_triplet(n, target, arr))

if __name__ == "__main__":
    main()