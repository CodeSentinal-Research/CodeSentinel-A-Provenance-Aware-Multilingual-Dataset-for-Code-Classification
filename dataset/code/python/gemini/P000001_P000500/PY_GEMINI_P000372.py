import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        records = {}
        idx = 1
        for _ in range(n):
            roll_no = tokens[idx]
            name = tokens[idx+1]
            records[roll_no] = name
            idx += 2
        target_roll = tokens[idx]
        if target_roll in records:
            print(f"{target_roll} {records[target_roll]}")
        else:
            print("Record Not Found")

if __name__ == '__main__':
    main()