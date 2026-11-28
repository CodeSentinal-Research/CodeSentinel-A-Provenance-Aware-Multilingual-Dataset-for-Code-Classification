import sys

def main():
    lines = sys.stdin.read().splitlines()
    if lines:
        n = int(lines[0].strip())
        strings = lines[1:n+1]
        for i, s in enumerate(strings):
            if s == "":
                print(i)
                return
        print(-1)

if __name__ == '__main__':
    main()