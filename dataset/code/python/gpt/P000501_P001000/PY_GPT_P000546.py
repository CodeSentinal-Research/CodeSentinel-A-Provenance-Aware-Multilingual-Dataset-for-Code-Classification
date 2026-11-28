# problem title : Jump Game VII
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        min_jump = int(tokens[1])
        max_jump = int(tokens[2])
        n = len(s)
        if s[-1] != '0':
            print("false")
            return
        dp = [False] * n
        dp[0] = True
        reach = 0
        for i in range(n):
            if not dp[i]: continue
            start = max(i + min_jump, reach + 1)
            end = min(i + max_jump, n - 1)
            for j in range(start, end + 1):
                if s[j] == '0':
                    dp[j] = True
            reach = max(reach, end)
        print("true" if dp[-1] else "false")
if __name__ == '__main__':
    main()
