def count_pairs(n, k, arr):
    arr.sort()
    count = 0
    for i in range(n):
        if i + 1 < n and abs(arr[i] - arr[i + 1]) == k:
            count += 1
    return count

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_pairs(n, k, arr))

if __name__ == "__main__":
    main()
This Python code defines a function `count_pairs` that counts the number of pairs in an array whose difference equals `k`. It first sorts the array, then iterates through the array, checking if the difference between the current element and the next one is equal to `k`. If it is, it increments a counter. Finally, it prints the counter.

The `main` function reads the number of elements `n` and the difference `k`, and then reads the array of `n` elements. It calls the `count_pairs` function with these values and prints the result.