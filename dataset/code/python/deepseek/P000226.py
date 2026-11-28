def count_inversions(arr):
    count = 0
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] > arr[j]:
                count += 1
    return count

def main():
    n = int(input().strip())
    arr = [int(x) for x in input().strip().split()]
    print(count_inversions(arr))

if __name__ == "__main__":
    main()