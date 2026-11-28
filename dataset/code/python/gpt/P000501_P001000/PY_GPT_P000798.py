# problem title : Maximum Length of Contiguous Array with Equal 0s and 1s
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        seen = {0: -1}
        cur = 0
        max_len = 0
        for i in range(n):
            cur += (1 if nums[i] == 1 else -1)
            if cur in seen:
                max_len = max(max_len, i - seen[cur])
            else:
                seen[cur] = i
        print(max_len)
if __name__ == '__main__':
    main()
