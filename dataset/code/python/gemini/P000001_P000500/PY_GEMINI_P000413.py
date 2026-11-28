import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        employees = []
        idx = 1
        for _ in range(n):
            employees.append((tokens[idx], tokens[idx+1], tokens[idx+2]))
            idx += 3
        target_dept = tokens[idx]
        for name, dept, status in employees:
            if dept == target_dept and status.lower() in ("active", "true", "1", "yes"):
                print(name)
if __name__ == '__main__':
    main()