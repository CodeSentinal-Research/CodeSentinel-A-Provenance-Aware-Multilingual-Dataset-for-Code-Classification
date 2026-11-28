def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))

    max_len = 0
    cur_len = 1
    max_len_even = max_len_odd = 0
    cur_len_even = cur_len_odd = 1

    for i in range(1, N):
        if nums[i-1] % 2 == nums[i]:
            cur_len += 1
        else:
            cur_len = 1

        if nums[i-1] % 2 == 0:
            cur_len_even += 1
            max_len_even = max(max_len_even, cur_len_even)
        else:
            cur_len_odd += 1
            max_len_odd = max(max_len_odd, cur_len_odd)

    max_len = max(max_len_even, max_len_odd)
    print(max_len)

if __name__ == "__main__":
    main()