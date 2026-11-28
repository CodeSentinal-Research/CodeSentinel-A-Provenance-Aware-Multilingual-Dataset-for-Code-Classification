import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        records = []
        idx = 1
        for _ in range(n):
            name = tokens[idx]
            dept = tokens[idx+1]
            records.append((name, dept))
            idx += 2
        target_dept = tokens[idx]
        matches = [name for name, dept in records if dept == target_dept]
        if matches:
            for m in matches:
                print(m)
        else:
            print("No Records Found")

if __name__ == '__main__':
    main()