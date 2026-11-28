def prefix_sum(arr):
    for i in range(1, len(arr)):
        arr[i] += arr[i - 1]
    return arr

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    prefix_sum_arr = prefix_sum(arr)
    print(" ".join(map(str, prefix_sum_arr)))

if __name__ == "__main__":
    main()