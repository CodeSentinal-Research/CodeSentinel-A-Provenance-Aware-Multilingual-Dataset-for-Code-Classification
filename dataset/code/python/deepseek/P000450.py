def find_kth_missing_positive(arr, k):
    num_set = set(arr)
    i = 1
    while k > 0:
        if i not in num_set:
            k -= 1
        i += 1
    return i - 1

def main():
    n, k = map(int, input().split())
    arr = sorted(set(map(int, input().split())))
    print(find_kth_missing_positive(arr, k))

if __name__ == "__main__":
    main()