# problem title : Number of Visible People in a Queue
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        heights = list(map(int, tokens[1:1+n]))
        ans = [0] * n
        stack = []
        for i in range(n - 1, -1, -1):
            h = heights[i]
            count = 0
            while stack and stack[-1] < h:
                stack.pop()
                count += 1
            if stack:
                count += 1
            ans[i] = count
            stack.append(h)
        print(*ans)
if __name__ == '__main__':
    main()
