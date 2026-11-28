# problem title : Beautiful Arrangement
# Solve the stated task using standard input and standard output.
import sys
def count_arrangements(n):
    used = [False] * (n + 1)
    def backtrack(pos):
        if pos > n: return 1
        count = 0
        for i in range(1, n + 1):
            if not used[i] and (i % pos == 0 or pos % i == 0):
                used[i] = True
                count += backtrack(pos + 1)
                used[i] = False
        return count
    return backtrack(1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(count_arrangements(n))
if __name__ == '__main__':
    main()
