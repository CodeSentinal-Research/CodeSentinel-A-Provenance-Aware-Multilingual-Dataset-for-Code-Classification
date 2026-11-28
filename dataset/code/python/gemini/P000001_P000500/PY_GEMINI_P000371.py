import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        records = {}
        idx = 1
        for _ in range(n):
            emp_id = tokens[idx]
            name = tokens[idx+1]
            records[emp_id] = name
            idx += 2
        target_id = tokens[idx]
        if target_id in records:
            print(f"{target_id} {records[target_id]}")
        else:
            print("Record Not Found")

if __name__ == '__main__':
    main()