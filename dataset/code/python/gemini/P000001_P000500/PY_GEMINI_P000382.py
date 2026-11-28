import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        records = {}
        idx = 1
        for _ in range(n):
            uname = tokens[idx]
            email = tokens[idx+1]
            records[uname] = email
            idx += 2
        target = tokens[idx]
        if target in records:
            print(records[target])
        else:
            print("User Not Found")

if __name__ == '__main__':
    main()