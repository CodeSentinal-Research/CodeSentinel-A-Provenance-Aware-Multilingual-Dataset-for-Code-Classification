def find_max_element(arr):
    return max(arr)

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    print(find_max_element(arr))

if __name__ == "__main__":
    main()