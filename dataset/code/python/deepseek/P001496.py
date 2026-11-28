def process_array(n, arr):
    for i in range(n - 1):
        if arr[i] == arr[i + 1]:
            arr[i] *= 2
            arr[i + 1] = 0

    arr = [num for num in arr if num != 0]
    zeroes = arr.count(0)
    arr = [num for num in arr if num == 0]
    arr.extend([0] * zeroes)

    return arr

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    result = process_array(N, arr)
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()