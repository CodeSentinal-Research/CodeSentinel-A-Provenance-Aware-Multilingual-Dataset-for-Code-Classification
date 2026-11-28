def sum_of_heap_elements(N, arr):
    return sum(arr)

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    result = sum_of_heap_elements(N, arr)
    print(result)

if __name__ == "__main__":
    main()