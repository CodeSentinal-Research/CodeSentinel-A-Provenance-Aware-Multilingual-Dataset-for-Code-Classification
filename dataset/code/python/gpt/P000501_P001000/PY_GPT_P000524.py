# problem title : Beautiful Towers I
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        h = list(map(int, tokens[1:1+n]))
        max_sum = 0
        for peak in range(n):
            curr_sum = h[peak]
            cur = h[peak]
            for i in range(peak - 1, -1, -1):
                cur = min(cur, h[i])
                curr_sum += cur
            cur = h[peak]
            for i in range(peak + 1, n):
                cur = min(cur, h[i])
                curr_sum += cur
            max_sum = max(max_sum, curr_sum)
        print(max_sum)
if __name__ == '__main__':
    main()
