def can_partition(n, arr):
    total_sum = sum(arr)
    if total_sum % n != 0:
        return "NO"
    else:
        target_sum = total_sum // n
        if sum(i for i in arr if i % n != 0):
            return "NO"
        else:
            return "YES"

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(can_partition(n, arr))

if __name__ == "__main__":
    main()