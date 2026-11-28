# problem title : Car Fleet II
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        cars = []
        idx = 1
        for _ in range(n):
            cars.append((float(tokens[idx]), float(tokens[idx+1])))
            idx += 2
        ans = [-1.0] * n
        stack = []
        for i in range(n - 1, -1, -1):
            p, s = cars[i]
            while stack:
                j = stack[-1]
                pj, sj = cars[j]
                if s <= sj or (ans[j] > 0 and (pj - p) / (s - sj) >= ans[j]):
                    stack.pop()
                else:
                    break
            if stack:
                j = stack[-1]
                pj, sj = cars[j]
                ans[i] = (pj - p) / (s - sj)
            stack.append(i)
        print(*(f"{x:.5f}" if x > 0 else "-1.00000" for x in ans))
if __name__ == '__main__':
    main()
