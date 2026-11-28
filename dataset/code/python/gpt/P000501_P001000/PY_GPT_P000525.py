# problem title : Beautiful Towers II
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        h = list(map(int, tokens[1:1+n]))
        left = [0] * n
        st = []
        for i in range(n):
            while st and h[st[-1]] >= h[i]: st.pop()
            if st:
                left[i] = left[st[-1]] + h[i] * (i - st[-1])
            else:
                left[i] = h[i] * (i + 1)
            st.append(i)
        right = [0] * n
        st = []
        for i in range(n - 1, -1, -1):
            while st and h[st[-1]] >= h[i]: st.pop()
            if st:
                right[i] = right[st[-1]] + h[i] * (st[-1] - i)
            else:
                right[i] = h[i] * (n - i)
            st.append(i)
        max_sum = max(left[i] + right[i] - h[i] for i in range(n))
        print(max_sum)
if __name__ == '__main__':
    main()
