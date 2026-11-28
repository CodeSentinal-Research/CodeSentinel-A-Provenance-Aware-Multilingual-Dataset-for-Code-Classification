import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        accounts = []
        idx = 1
        for _ in range(n):
            accounts.append((tokens[idx], int(tokens[idx+1])))
            idx += 2
        months = int(tokens[idx])
        for acc, m in accounts:
            if m >= months:
                print(acc)
if __name__ == '__main__':
    main()