import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        idx = 1
        for _ in range(n):
            slot = tokens[idx]
            status = tokens[idx+1]
            if status.lower() in ("vacant", "available", "free", "empty", "true", "1", "yes"):
                print(slot)
            idx += 2
if __name__ == '__main__':
    main()