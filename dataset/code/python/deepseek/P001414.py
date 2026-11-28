def count_distinct_absolute_values(arr):
    return len(set(abs(x) for x in arr))

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(count_distinct_absolute_values(arr))

if __name__ == "__main__":
    main()