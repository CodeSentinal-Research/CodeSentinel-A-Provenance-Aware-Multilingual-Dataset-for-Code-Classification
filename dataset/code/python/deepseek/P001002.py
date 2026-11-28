def check_max_heap(arr):
    n = len(arr)
    for i in range(n//2):
        if arr[i] < arr[2*i+1]:
            return 'NO'
        if 2*i+2 < n and arr[i] < arr[2*i+2]:
            return 'NO'
    return 'YES'

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(check_max_heap(arr))

if __name__ == "__main__":
    main()