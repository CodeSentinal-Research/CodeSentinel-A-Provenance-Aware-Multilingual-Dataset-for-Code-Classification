def max_abs_prefix_sum(n, arr):
    prefix_sums = [0]
    curr_sum = 0
    for num in arr:
        curr_sum += num
        prefix_sums.append(curr_sum)
    return max(prefix_sums)

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(max_abs_prefix_sum(n, arr))

if __name__ == "__main__":
    main()