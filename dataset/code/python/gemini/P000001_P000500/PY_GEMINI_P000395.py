import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        idx = 1
        for _ in range(n):
            room = tokens[idx]
            status = tokens[idx+1]
            if status.lower() in ("available", "true", "1", "yes", "free"):
                print(room)
            idx += 2

if __name__ == '__main__':
    main()