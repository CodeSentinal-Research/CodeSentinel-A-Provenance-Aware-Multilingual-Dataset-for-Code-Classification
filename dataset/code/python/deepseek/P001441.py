Here is the Python code for the problem:

def count_pairs(n, k, arr):
    arr.sort()
    count = 0
    for i in range(n):
        for j in range(i+1, n):
            if abs(arr[i] - arr[j]) == k:
                count += 1
    return count

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_pairs(n, k, arr))

if __name__ == "__main__":
    main()

This code first sorts the input array. Then, it iterates through the array and for each pair of elements, it checks if the difference between them is equal to K. If it is, it increments a counter. At the end, it returns the count of pairs that satisfy the condition.