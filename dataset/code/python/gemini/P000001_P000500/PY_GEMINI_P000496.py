import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:1+n]))
        MOD = 10**9 + 7
        st = []
        prev_less = [-1] * n
        for i in range(n):
            while st and arr[st[-1]] >= arr[i]: st.pop()
            prev_less[i] = st[-1] if st else -1
            st.append(i)
        st = []
        next_less = [n] * n
        # Process from right to left
        for i in range(n - 1, -1, -1):
            while st and arr[st[-1]] > arr[i]: st.pop()
            next_less[i] = st[-1] if st else n
            st.append(i)
        ans = 0
        for i in range(n):
            ans = (ans + arr[i] * (i - prev_less[i]) * (next_less[i] - i)) % MOD
        print(ans)
if __name__ == '__main__':
    main()