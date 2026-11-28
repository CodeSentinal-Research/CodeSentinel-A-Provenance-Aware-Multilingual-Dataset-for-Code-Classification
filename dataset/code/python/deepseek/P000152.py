def find_min_product(n, arr):
    arr.sort()
    return arr[0] * arr[1]

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    print(find_min_product(n, arr))

if __name__ == "__main__":
    main()