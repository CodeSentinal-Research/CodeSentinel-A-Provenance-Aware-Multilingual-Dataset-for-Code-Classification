import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        records = {}
        idx = 1
        for _ in range(n):
            hid = tokens[idx]
            name = tokens[idx+1]
            records[hid] = name
            idx += 2
        target = tokens[idx]
        if target in records:
            print(f"{target} {records[target]}")
        else:
            print("Hotel Not Found")

if __name__ == '__main__':
    main()