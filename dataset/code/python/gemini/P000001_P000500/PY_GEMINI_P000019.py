import sys

def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        for i in range(1, 11):
            print(f"{n} * {i} = {n * i}")

if __name__ == '__main__':
    main()