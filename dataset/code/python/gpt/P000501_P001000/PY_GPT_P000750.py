# problem title : Lexicographical Numbers Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def lex_numbers(n):
    def dfs(cur):
        if cur > n: return
        print(cur)
        for i in range(10):
            if cur * 10 + i <= n:
                dfs(cur * 10 + i)
            else:
                break
    for i in range(1, 10):
        if i <= n: dfs(i)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        lex_numbers(n)
if __name__ == '__main__':
    main()
