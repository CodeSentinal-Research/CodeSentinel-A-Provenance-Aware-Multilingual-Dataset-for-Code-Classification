def find_max_index(arr):
    max_value = max(arr)
    max_index = arr.index(max_value)
    return max_index

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    print(find_max_index(arr))

if __name__ == "__main__":
    main()