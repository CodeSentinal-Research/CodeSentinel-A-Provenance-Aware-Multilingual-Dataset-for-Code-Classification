import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        idx = 1
        for _ in range(n):
            uname = tokens[idx]
            status = tokens[idx+1]
            if status.lower() in ("active", "true", "1", "yes", "enabled"):
                print(uname)
            idx += 2

if __name__ == '__main__':
    main()