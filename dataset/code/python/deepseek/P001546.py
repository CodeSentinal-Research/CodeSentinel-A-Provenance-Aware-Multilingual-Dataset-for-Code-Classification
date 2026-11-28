Here is a Python solution that uses a greedy approach:

def max_alternating_subarray(arr):
    n = len(arr)
    max_len = 1
    cur_len = 1

    prev_diff = arr[0]
    for i in range(1, n):
        if arr[i] == prev_diff:
            cur_len += 1
        else:
            max_len = max(max_len, cur_len)
            cur_len = 1
        prev_diff = arr[i]

    max_len = max(max_len, cur_len)
    return max_len

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    print(max_alternating_subarray(arr))

if __name__ == "__main__":
    main()

In this solution, we iterate over the array and keep track of the maximum length of the alternating subarray we have seen so far. If the current element is the same as the previous one, we just increase the current length. Otherwise, we update the maximum length if the current length is longer. We also update the current length to 1 when we change the previous element.