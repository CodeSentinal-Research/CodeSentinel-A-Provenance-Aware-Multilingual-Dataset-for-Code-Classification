def findPeak(arr, n):
    max_element = arr[0]
    for i in range(1, n):
        if arr[i] > max_element:
            max_element = arr[i]
    return max_element

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    print(findPeak(arr, n))

if __name__ == "__main__":
    main()