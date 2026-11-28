import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        users = tokens[1:n+1]
        prefix = tokens[n+1]
        for u in users:
            if u.startswith(prefix):
                print(u)
if __name__ == '__main__':
    main()