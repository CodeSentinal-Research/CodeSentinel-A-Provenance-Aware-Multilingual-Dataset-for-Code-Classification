def find_longest_subarray():
    n = int(input().strip())
    arr = [int(x) for x in input().strip().split()]
    count = {0: [0]}
    max_len = 0
    cur_len = 0
    for i, bit in enumerate(arr):
        cur_len += 1
        if bit == 0:
            cur_len -= 1
        else:
            cur_len += 1
        if cur_len not in count:
            count[cur_len] = [i]
        else:
            count[cur_len].append(i)
        if cur_len > max_len:
            max_len = cur_len
    return max_len

def main():
    print(find_longest_subarray())

if __name__ == "__main__":
    main()