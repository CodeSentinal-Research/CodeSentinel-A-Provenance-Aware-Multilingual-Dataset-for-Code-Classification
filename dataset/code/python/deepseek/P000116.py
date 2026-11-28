def find_missing_number(arr):
    n = len(arr) + 1
    total_sum = n * (n+1) / 2
    sum_of_arr = sum(arr)
    return total_sum - sum_of_arr

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    missing = find_missing_number(arr)
    print(int(missing))

if __name__ == "__main__":
    main()