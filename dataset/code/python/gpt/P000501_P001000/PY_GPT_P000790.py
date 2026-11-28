# problem title : Continuous Subarray Sum
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        seen = {0: -1}
        cur = 0
        ans = False
        for i in range(n):
            cur = (cur + nums[i]) % k
            if cur in seen:
                if i - seen[cur] >= 2:
                    ans = True
                    break
            else:
                seen[cur] = i
        print("true" if ans else "false")
if __name__ == '__main__':
    main()
