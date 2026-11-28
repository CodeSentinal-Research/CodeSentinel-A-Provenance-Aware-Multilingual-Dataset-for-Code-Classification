def count_subarrays(arr):
    n = len(arr)
    count = 0
    for i in range(n):
        distinct = set()
        for j in range(i, n):
            distinct.add(arr[j])
            if len(distinct) == n - i:
                count += 1
                break
    return count

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(count_subarrays(arr))

if __name__ == "__main__":
    main()